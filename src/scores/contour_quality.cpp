#include "contour_quality.hpp"

float Scores::ContourQuality::calculateContourCoverage(
    const std::vector<cv::Point>& contour,
    const cv::Mat& image)
{
    int contourPoints = contour.size();
    int imagePixels = image.rows * image.cols;
    float coverage = static_cast<float>(contourPoints) / imagePixels;
    return coverage;
}
