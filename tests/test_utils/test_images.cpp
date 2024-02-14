#include "test_images.hpp"

#include "file_utils.hpp"

#include <opencv2/imgcodecs.hpp>

std::vector<cv::Mat> TestUtils::getTestImages()
{
    std::vector<cv::Mat> images;
    auto pathsToImages =
        FileUtils::getFilesInFolder(FileUtils::getWorkspaceAbsolutePath() / TEST_IMAGES_FOLDER);

    for (const auto& path : pathsToImages)
    {
        images.push_back(cv::imread(path));
    }
    return images;
}