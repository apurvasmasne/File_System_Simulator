#include "gtest/gtest.h"
#include "file_system.h"

class FileSystemTest : public ::testing::Test
{
protected:
    FileSystem fs;
};

TEST_F(FileSystemTest, CreateFile)
{
    EXPECT_TRUE(fs.createFile("testfile.txt", 1024));
}

TEST_F(FileSystemTest, DeleteFile)
{
    fs.createFile("testfile.txt", 1024);
    EXPECT_TRUE(fs.deleteFile("testfile.txt"));
}

TEST_F(FileSystemTest, ListFiles)
{
    fs.createFile("file1.txt", 1024);
    fs.createFile("file2.txt", 2048);

    // You may need to redirect stdout to capture and test the printed output
    testing::internal::CaptureStdout();
    fs.listFiles();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("file1.txt") != std::string::npos);
    EXPECT_TRUE(output.find("file2.txt") != std::string::npos);
}

TEST_F(FileSystemTest, WriteReadFile)
{
    fs.createFile("testfile.txt", 1024);
    fs.writeFile("testfile.txt", "Test data.");
    testing::internal::CaptureStdout();
    fs.readFile("testfile.txt");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Test data.") != std::string::npos);
}
