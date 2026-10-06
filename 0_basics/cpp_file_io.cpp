#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << "=== C++ File I/O Demonstration ===" << std::endl;
    const std::string filename = "temp_demo.txt";

    // Writing
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Error opening file for write\n";
        return 1;
    }
    outfile << "Line 1: DSA in C and C++\n";
    outfile << "Line 2: Fast, Robust, Efficient\n";
    outfile.close();

    // Reading
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file for read\n";
        return 1;
    }
    std::string line;
    std::cout << "Read contents:\n";
    while (std::getline(infile, line)) {
        std::cout << "  " << line << std::endl;
    }
    infile.close();

    // Clean up temporary file
    std::remove(filename.c_str());
    return 0;
}
