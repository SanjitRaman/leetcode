#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("instr_mem.mem", std::ios::binary);
    std::ofstream outputFile("instr_mem_little_endian.mem", std::ios::binary);

    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    if (!outputFile) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    while(!inputFile.eof()) {
        std::string line;
        // read a line
        std::getline(inputFile, line);

        // create a stream from line
        std::istringstream iss(line);
        std::vector<std::string> line_bytes;
        for(int i = 0; i < 4; i++) {
            std::string my_byte;
            iss >> my_byte;
            line_bytes.push_back(my_byte);
        }
        
        // write the line_bytes in reverse order to the output file
        std::reverse(line_bytes.begin(), line_bytes.end());

        for(int i = 0; i < 4; i++) {
            outputFile << line_bytes[i] << " ";
        }
        outputFile << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "File converted successfully." << std::endl;

    return 0;
}
