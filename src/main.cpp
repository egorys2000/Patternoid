#include <stdio.h>
#include <string>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "cv_utils.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return EXIT_FAILURE;
    }
    cv::Mat src = cv::imread(argv[1], cv::IMREAD_COLOR);
    if (!src.data)
    {
        printf("No image data \n");
        return EXIT_FAILURE;
    }
    const std::string windowName = "Display Image";
    cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);

    cv::Mat dst;

    auto anchor = cv::Point(-1, -1);
    auto delta = 0;
    auto ddepth = -1;

    auto kernel_size = 5;
    auto kernel =
        cv::Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size * kernel_size);
    cv::filter2D(src, dst, ddepth, kernel, anchor, delta, cv::BORDER_DEFAULT);

    cv_utils::showImageInNewWindow(dst, windowName);

    return EXIT_SUCCESS;
}