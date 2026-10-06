#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * Topic: C++ File I/O Demonstration
 * Module: 0_basics
 */

int main() {
    const std::string filename = "/tmp/demo_file_io_test.txt";

    // Writing
    {
        std::ofstream outfile(filename);
        assert(outfile.is_open());
        outfile << "Line 1: DSA in C++20\n";
        outfile << "Line 2: Fast, Robust, Efficient\n";
    }

    // Reading & verification
    {
        std::ifstream infile(filename);
        assert(infile.is_open());
        std::string line;
        std::vector<std::string> lines;
        while (std::getline(infile, line)) {
            lines.push_back(line);
        }
        assert(lines.size() == 2);
        assert(lines[0] == "Line 1: DSA in C++20");
        assert(lines[1] == "Line 2: Fast, Robust, Efficient");
    }

    // Clean up temporary file
    assert(std::remove(filename.c_str()) == 0);

    std::cout << "[PASS] 0_basics/cpp_file_io: all tests passed!\n";
    return 0;
}
