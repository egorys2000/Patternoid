#pragma once

#include <opencv2/core.hpp>

#include <filesystem>
#include <vector>

namespace TestUtils
{
std::vector<cv::Mat> getTestImages();

const std::filesystem::path TEST_IMAGES_FOLDER = "img/";
} // namespace TestUtils