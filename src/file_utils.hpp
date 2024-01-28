#pragma once

#include <string>

namespace file_utils
{
std::string getFileNameFromPath(const std::string& filePath);
void createFolderIfNotExists(const std::string& folderPath);

const std::string DEFAULT_OUTPUT_FOLDER = "img/processed/";
} // namespace file_utils
