#include "file_operations.h"
#include <iostream>
#include <fstream>

bool FileOperations::createFile(const std::string &fileName, int fileSize)
{
    fileMetadata.addFile(fileName, fileSize);

    std::ofstream file(fileName);
    if (!file)
    {
        std::cerr << "Failed to create file: " << fileName << std::endl;
        return false;
    }

    file.close();
    std::cout << "File created: " << fileName << std::endl;
    return true;
}

bool FileOperations::deleteFile(const std::string &fileName)
{
    FileNode *file = fileMetadata.findFile(fileName);
    if (file)
    {
        fileMetadata.deleteFile(fileName);
        if (remove(fileName.c_str()) != 0)
        {
            std::cerr << "Failed to delete file: " << fileName << std::endl;
            return false;
        }
        std::cout << "File deleted: " << fileName << std::endl;
        return true;
    }
    return false;
}

void FileOperations::listFiles() const
{
    FileNode *files = fileMetadata.listFiles();
    if (!files)
    {
        std::cout << "No files in the system." << std::endl;
        return;
    }

    while (files)
    {
        std::cout << "File Name: " << files->fileName << ", Size: " << files->fileSize << " bytes" << std::endl;
        files = files->next;
    }
}

bool FileOperations::writeFile(const std::string &fileName, const std::string &data)
{
    std::ofstream file(fileName);
    if (!file)
    {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return false;
    }

    file << data;
    file.close();
    std::cout << "Data written to file: " << fileName << std::endl;
    return true;
}

bool FileOperations::readFile(const std::string &fileName)
{
    std::ifstream file(fileName);
    if (!file)
    {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return false;
    }

    std::string line;
    while (getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();
    return true;
}
