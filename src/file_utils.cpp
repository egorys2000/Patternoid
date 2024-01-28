#include "file_utils.hpp"

#include <filesystem>

std::string file_utils::getFileNameFromPath(const std::string& filePath)
{
    return std::filesystem::path(filePath).filename().string();
}

void file_utils::createFolderIfNotExists(const std::string& folderPath)
{
    if (!std::filesystem::exists(folderPath))
    {
        std::filesystem::create_directory(folderPath);
    }
}
