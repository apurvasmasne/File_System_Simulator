#include <iostream>
#include "file_system.h"

int main()
{
    FileSystem fs;

    fs.createFile("file1.txt", 1024);
    fs.createFile("file2.txt", 2048);

    fs.listFiles();

    fs.writeFile("file1.txt", "Hello, world!");
    fs.readFile("file1.txt");

    fs.deleteFile("file2.txt");

    fs.listFiles();

    return 0;
}
