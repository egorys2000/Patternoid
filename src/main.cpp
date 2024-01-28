#include <stdio.h>
#include <string>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "contour_map.hpp"
#include "cv_utils.hpp"
#include "file_utils.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        return EXIT_FAILURE;
    }
    std::string testImgPath = argv[1];
    cv::Mat src = cv::imread(testImgPath, cv::IMREAD_COLOR);
    if (!src.data)
    {
        printf("No image data \n");
        return EXIT_FAILURE;
    }
    const std::string windowName = "Display Image";

    contour::preprocess_image(src);
    contour::find_contours(src);

    file_utils::createFolderIfNotExists(file_utils::DEFAULT_OUTPUT_FOLDER);
    auto outFilePath =
        file_utils::DEFAULT_OUTPUT_FOLDER + file_utils::getFileNameFromPath(testImgPath);

    printf("Saving to %s\n", outFilePath.c_str());
    cv::imwrite(outFilePath, src);

    return EXIT_SUCCESS;
}