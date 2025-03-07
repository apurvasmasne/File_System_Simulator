# File System Simulator

A simple C++ program that simulates basic file system operations, such as creating, deleting, listing, writing, and reading files. The simulator uses linked lists and hash tables to manage file metadata. It also integrates with Google Test for unit testing of the file system operations.

## Features

- **File and Directory Operations**: Simulates the creation, deletion, and listing of files.
- **Metadata Management**: Uses linked lists and hash tables to manage file metadata.
- **Unit Testing**: Implements unit tests for file operations using **Google Test**.
- **File I/O**: Supports reading from and writing to files.
  
## Technologies

- **C++**: Main programming language.
- **Linked Lists**: For managing file metadata.
- **Hash Tables**: For efficient file lookup.
- **Google Test**: For unit testing.
- **File I/O**: Reading and writing to files.
  
## Prerequisites

To build and run this project, you need to have the following installed:

- **C++ Compiler** (e.g., GCC or Clang)
- **CMake** (for building the project)
- **Google Test** (for running the unit tests)

### Google Test Installation

If you don't have **Google Test** installed on your machine, you can install it using one of the following methods:

#### Option 1: Install via Package Manager (Linux)

- **Ubuntu/Debian**:
  ```bash
  sudo apt-get install libgtest-dev

### Build from Source

git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ..
make
sudo make install
