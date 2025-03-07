#include "file_system.h"
#include <iostream>

bool FileSystem::createFile(const std::string &fileName, int fileSize)
{
    return fileOps.createFile(fileName, fileSize);
}

bool FileSystem::deleteFile(const std::string &fileName)
{
    return fileOps.deleteFile(fileName);
}

void FileSystem::listFiles()
{
    fileOps.listFiles();
}

bool FileSystem::writeFile(const std::string &fileName, const std::string &data)
{
    return fileOps.writeFile(fileName, data);
}

bool FileSystem::readFile(const std::string &fileName)
{
    return fileOps.readFile(fileName);
}
