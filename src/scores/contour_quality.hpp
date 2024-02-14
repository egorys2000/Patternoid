#pragma once

#include <opencv2/core.hpp>
#include <vector>

namespace Scores
{
namespace ContourQuality
{
float calculateContourCoverage(const std::vector<cv::Point>& contour, const cv::Mat& image);
} // namespace ContourQuality
} // namespace Scores
