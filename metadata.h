#ifndef METADATA_H
#define METADATA_H

#include <string>

struct FileNode
{
    std::string fileName;
    int fileSize; // in bytes
    FileNode *next;

    FileNode(const std::string &name, int size)
        : fileName(name), fileSize(size), next(nullptr) {}
};

class FileMetadata
{
private:
    FileNode *head;

public:
    FileMetadata();
    ~FileMetadata();

    void addFile(const std::string &fileName, int fileSize);
    void deleteFile(const std::string &fileName);
    FileNode *listFiles() const;
    FileNode *findFile(const std::string &fileName) const;
};

#endif
