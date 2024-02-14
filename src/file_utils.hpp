#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace FileUtils
{
std::string getFileNameFromPath(const std::string& filePath);
void createFolderIfNotExists(const std::string& folderPath);
std::vector<std::string> getFilesInFolder(const std::string& folderPath);
std::filesystem::path getWorkspaceAbsolutePath();

const std::string DEFAULT_OUTPUT_FOLDER = "img/processed/";
} // namespace FileUtils
