#include "metadata.h"
#include <iostream>

FileMetadata::FileMetadata() : head(nullptr) {}

FileMetadata::~FileMetadata()
{
    FileNode *current = head;
    while (current)
    {
        FileNode *toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void FileMetadata::addFile(const std::string &fileName, int fileSize)
{
    FileNode *newFile = new FileNode(fileName, fileSize);
    newFile->next = head;
    head = newFile;
}

void FileMetadata::deleteFile(const std::string &fileName)
{
    FileNode *current = head;
    FileNode *prev = nullptr;

    while (current && current->fileName != fileName)
    {
        prev = current;
        current = current->next;
    }

    if (!current)
    {
        std::cerr << "File not found!" << std::endl;
        return;
    }

    if (prev)
    {
        prev->next = current->next;
    }
    else
    {
        head = current->next;
    }

    delete current;
}

FileNode *FileMetadata::listFiles() const
{
    return head;
}

FileNode *FileMetadata::findFile(const std::string &fileName) const
{
    FileNode *current = head;
    while (current)
    {
        if (current->fileName == fileName)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
