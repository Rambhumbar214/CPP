/*Write a C++ program to copy the contents of one file to another */
#include <iostream>
#include <fstream>

int main() {
    // Specify the source and destination file names
    const char* sourceFileName = "source.txt";
    const char* destinationFileName = "destination.txt";

    // Open the source file in binary mode
    std::ifstream sourceFile(sourceFileName, std::ios::binary);
    if (!sourceFile) {
        std::cerr << "Error: Could not open source file '" << sourceFileName << "' for reading." << std::endl;
        return 1;
    }

    // Open the destination file in binary mode
    std::ofstream destinationFile(destinationFileName, std::ios::binary);
    if (!destinationFile) {
        std::cerr << "Error: Could not open destination file '" << destinationFileName << "' for writing." << std::endl;
        return 1;
    }

    // Copy the contents from source to destination
    destinationFile << sourceFile.rdbuf();

    // Check for any errors during the copy process
    if (!destinationFile) {
        std::cerr << "Error: Failed to write to destination file '" << destinationFileName << "'." << std::endl;
        return 1;
    }

    std::cout << "File copied successfully from '" << sourceFileName << "' to '" << destinationFileName << "'." << std::endl;
    return 0;
}
