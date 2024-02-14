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

    auto preprocessedImage = Contour::adaptivePreprocessImage(src);
    auto contour = Contour::findContourPoints(preprocessedImage);
    auto contourImage = Contour::drawControurPoints(src.cols, src.rows, contour);

    FileUtils::createFolderIfNotExists(FileUtils::DEFAULT_OUTPUT_FOLDER);
    auto outFilePath =
        FileUtils::DEFAULT_OUTPUT_FOLDER + FileUtils::getFileNameFromPath(testImgPath);

    printf("Saving to %s\n", outFilePath.c_str());
    cv::imwrite(outFilePath, contourImage);

    return EXIT_SUCCESS;
}