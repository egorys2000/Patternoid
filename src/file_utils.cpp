#include "file_utils.hpp"

std::string FileUtils::getFileNameFromPath(const std::string& filePath)
{
    return std::filesystem::path(filePath).filename().string();
}

void FileUtils::createFolderIfNotExists(const std::string& folderPath)
{
    if (!std::filesystem::exists(folderPath))
    {
        std::filesystem::create_directory(folderPath);
    }
}

std::vector<std::string> FileUtils::getFilesInFolder(const std::string& folderPath)
{
    std::vector<std::string> filePaths;
    for (const auto& entry : std::filesystem::directory_iterator(folderPath))
    {
        if (entry.is_regular_file())
        {
            filePaths.push_back(entry.path().string());
        }
    }
    return filePaths;
}

std::filesystem::path FileUtils::getWorkspaceAbsolutePath()
{
    std::filesystem::path currentPath = std::filesystem::current_path();

    if (currentPath.filename() == "Patternoid")
    {
        return currentPath.parent_path();
    }

    while (currentPath.filename() != "Patternoid")
    {
        currentPath = currentPath.parent_path();
        if (currentPath == currentPath.root_path())
        {
            return "";
        }
    }

    return currentPath;
}
