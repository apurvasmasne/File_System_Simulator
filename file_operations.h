#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <string>
#include "metadata.h"

class FileOperations
{
private:
    FileMetadata fileMetadata;

public:
    bool createFile(const std::string &fileName, int fileSize);
    bool deleteFile(const std::string &fileName);
    void listFiles() const;
    bool writeFile(const std::string &fileName, const std::string &data);
    bool readFile(const std::string &fileName);
};

#endif
