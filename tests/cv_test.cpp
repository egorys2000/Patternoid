#include <gtest/gtest.h>

#include "cv_utils.hpp"
TEST(CVMainTest, SmokeTest)
{
    auto windowName = "Black Image";

    cv::Mat blackImg = cv::Mat::zeros(500, 500, CV_8UC3);
    cv_utils::showImageInNewWindow(blackImg, windowName);
}
