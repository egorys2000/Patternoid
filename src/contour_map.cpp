#include "contour_map.hpp"

#include "scores/contour_quality.hpp"

#include <iostream>
#include <opencv2/imgproc.hpp>

cv::Mat Contour::adaptivePreprocessImage(const cv::Mat& image, float minCoverage, float maxCoverage)
{
    const u_int minBlurKernelSize = 5;
    const u_int maxBlurKernelSize = 21;

    cv::Mat preprocessedImage = image.clone();

    for (int blurKernelSize = minBlurKernelSize; blurKernelSize <= maxBlurKernelSize;
         blurKernelSize += 2)
    {
        preprocessedImage = preprocessImage(image, blurKernelSize);
        auto contour = findContourPoints(preprocessedImage);
        auto coverage = Scores::ContourQuality::calculateContourCoverage(contour, image);
        if (coverage > minCoverage && coverage < maxCoverage)
        {
            return preprocessedImage;
        }
    }

    return preprocessedImage;
}

cv::Mat Contour::preprocessImage(
    const cv::Mat& image,
    int blurKernelSize,
    int laplacianKernelSize,
    float thresholdRangeFactor)
{
    cv::Mat processedImage = image.clone();
    // Convert to grayscale
    if (image.channels() > 1)
    {
        cv::cvtColor(image, processedImage, cv::COLOR_RGB2GRAY);
    }

    // Blur the image
    cv::GaussianBlur(processedImage, processedImage, cv::Size(blurKernelSize, blurKernelSize), 0);

    // Apply Laplacian filter
    cv::Laplacian(processedImage, processedImage, image.type(), laplacianKernelSize);

    // Apply threshold
    double thresholdValue = 0;
    double thresholdMaxValue = 1.0;
    cv::minMaxLoc(image, &thresholdValue, &thresholdMaxValue);
    double srcRange = thresholdMaxValue - thresholdValue;
    auto dstRange = srcRange * thresholdRangeFactor;
    thresholdValue += srcRange - dstRange;
    thresholdMaxValue -= srcRange - dstRange;
    cv::threshold(
        processedImage, processedImage, thresholdValue, thresholdMaxValue, cv::THRESH_BINARY);

    return processedImage;
}

std::vector<cv::Point> Contour::findContourPoints(const cv::Mat& image)
{
    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(image, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

    std::vector<cv::Point> mergedPoints;
    for (const auto& contour : contours)
    {
        mergedPoints.insert(mergedPoints.end(), contour.begin(), contour.end());
    }
    return mergedPoints;
}

cv::Mat Contour::drawControurPoints(
    const u_int imgWidth,
    const u_int imgHeight,
    const std::vector<cv::Point>& points)
{
    cv::Mat image = cv::Mat::zeros(imgHeight, imgWidth, CV_8UC3);
    cv::Vec3b white(255, 255, 255);
    // draw white points on image
    for (const auto& point : points)
    {
        if (point.x >= 0 && point.x < imgWidth && point.y >= 0 && point.y < imgHeight)
            image.at<cv::Vec3b>(point) = white;
    }
    return image;
}
