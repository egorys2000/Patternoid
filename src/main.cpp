#include <stdio.h>
#include <string>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "contour_map.hpp"
#include "cv_utils.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        return EXIT_FAILURE;
    }
    cv::Mat src = cv::imread(argv[1], cv::IMREAD_COLOR);
    if (!src.data)
    {
        printf("No image data \n");
        return EXIT_FAILURE;
    }
    const std::string windowName = "Display Image";

    contour::preprocess_image(src);
    contour::find_contours(src);

    cv_utils::showImageInNewWindow(src, windowName);

    return EXIT_SUCCESS;
}