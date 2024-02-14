#pragma once

#include <opencv2/core.hpp>

#include <vector>

namespace Contour
{
cv::Mat adaptivePreprocessImage(
    const cv::Mat& image,
    float minCoverage = 0.015,
    float maxCoverage = 0.05);

cv::Mat preprocessImage(
    const cv::Mat& image,
    int blurKernelSize = 13,
    int laplacianKernelSize = 5,
    float thresholdRangeFactor = 0.7);

std::vector<cv::Point> findContourPoints(const cv::Mat& image);
cv::Mat drawControurPoints(
    const u_int imgWidth,
    const u_int imgHeight,
    const std::vector<cv::Point>& contour);
} // namespace Contour
