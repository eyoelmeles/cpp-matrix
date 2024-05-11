#include "CLIHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

void CLIHandler::handleCommandLine(int argc, char* argv[]) {
    std::string matrixFilePath;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-m" && i + 1 < argc) {
            matrixFilePath = argv[++i];
        } else  {
            std::cerr << "Unknown option or missing argument for " << arg << std::endl;
            return;
        }
    }
    if (!matrixFilePath.empty()) {
        processFile(matrixFilePath);
    } else {
        std::cerr << "Usage: " << argv[0] << "-m matrix_file.txt" << std::endl;
    }
}

Matrix CLIHandler::parseMatrix(const std::string& matrixStr) {
    std::vector<std::vector<double>> rows;
    std::stringstream ss(matrixStr);
    std::string rowStr;

    while (std::getline(ss, rowStr, ',')) {
        std::vector<double> row;
        std::stringstream rowStream(rowStr);
        double value;
        while (rowStream >> value) {
            row.push_back(value);
        }
        rows.push_back(row);
    }
    Matrix mat(rows.size(), rows[0].size());
    for (size_t i = 0; i < rows.size(); ++i) {
        for (size_t j = 0; j < rows[i].size(); ++j) {
            mat.set(i, j, rows[i][j]);
        }
    }
    return mat;
}

void CLIHandler::processFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.front() == '[' && line.back() == ']') {
            Matrix mat = parseMatrix(line.substr(1, line.length() - 2));
            mat.display();
            std::cout << std::endl;
        }
    }
}