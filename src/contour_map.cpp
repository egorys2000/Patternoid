#include "contour_map.hpp"

#include <iostream>
#include <opencv2/imgproc.hpp>

void contour::preprocess_image(cv::Mat& image)
{
    // Convert to grayscale
    if (image.channels() > 1)
    {
        cv::cvtColor(image, image, cv::COLOR_RGB2GRAY);
    }

    // Blur the image
    auto blurKernelSize = 13;
    cv::GaussianBlur(image, image, cv::Size(blurKernelSize, blurKernelSize), 0);

    // Apply Laplacian filter
    auto laplacianKernelSize = 5;
    cv::Laplacian(image, image, image.type(), laplacianKernelSize);

    // Apply threshold
    double thresholdValue = 0;
    double thresholdMaxValue = 1.0;
    cv::minMaxLoc(image, &thresholdValue, &thresholdMaxValue);
    double srcRange = thresholdMaxValue - thresholdValue;
    auto dstRange = srcRange * 0.7;
    thresholdValue += srcRange - dstRange;
    thresholdMaxValue -= srcRange - dstRange;
    cv::threshold(image, image, thresholdValue, thresholdMaxValue, cv::THRESH_BINARY);
}

void contour::find_contours(cv::Mat& image)
{
    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(image, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

    // Draw contours
    cv::Mat drawing = cv::Mat::zeros(image.size(), CV_8UC3);
    for (size_t i = 0; i < contours.size(); i++)
    {
        cv::Scalar color = cv::Scalar(255, 255, 255);
        cv::drawContours(drawing, contours, (int)i, color, 1, cv::LINE_8, hierarchy, 0);
    }

    image = drawing;
}
