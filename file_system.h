#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <string>
#include "file_operations.h"

class FileSystem
{
private:
    FileOperations fileOps;

public:
    bool createFile(const std::string &fileName, int fileSize);
    bool deleteFile(const std::string &fileName);
    void listFiles();
    bool writeFile(const std::string &fileName, const std::string &data);
    bool readFile(const std::string &fileName);
};

#endif
