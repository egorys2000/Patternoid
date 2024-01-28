#pragma once

#include <opencv2/core.hpp>

namespace contour
{
void preprocess_image(cv::Mat& image);

void find_contours(cv::Mat& image);
} // namespace contour
