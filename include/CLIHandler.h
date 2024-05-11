#ifndef CLIHANDLER_H
#define CLIHANDLER_H

#include <string>
#include "Matrix.h"

class CLIHandler {
    public:
        static void handleCommandLine(int argc, char* argv[]);
    private:
        static Matrix parseMatrix(const std::string& matrixStr);
        static void processFile(const std::string& filename);
};

#endif