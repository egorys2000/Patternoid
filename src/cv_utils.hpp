#pragma once

#include <opencv2/core.hpp>
#include <string>

namespace cv_utils
{
void showImageInNewWindow(const cv::Mat& image, const std::string& windowName);
} // namespace cv_utils
