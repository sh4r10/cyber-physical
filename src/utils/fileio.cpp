#include <fstream>
#include <sstream>
#include <string>
#include "fileio.hpp"
#include <iostream>

std::string read_file(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void write_file(const std::string& filename, const std::string& data) {
    // Create an output file stream object named file
    std::ofstream file(filename);

    // Check if the file was opened successfully
    if (!file.is_open()) {
        // Output an error message to the standard error stream and return an error code of 1
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }

    // Write data to the file
    file << data;

    // Flush and close the file stream
    file.flush();
    file.close();
}


