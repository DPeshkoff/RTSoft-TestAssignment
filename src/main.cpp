// Copyright 2021 DPeshkoff;
// Distributed under the GNU General Public License, Version 3.0. (See
// accompanying file LICENSE)

#include <unistd.h>  // TODO - amount of processors

#include <fstream>   // ...
#include <iostream>  // ...
#include <string>    // ...

#include "field.h"  // ...

/*!
        \brief main.

    Параметры: имя файла с текстовыми исходниками карты. 
*/
int main(int argc, char** argv) {
    if (argc > 1) {
        std::cout << argv[1] << std::endl;
    } else {
        std::cerr << "\033[1;31m[ERROR]\033[0m Not enough arguments."
                  << std::endl;
        std::cerr << "Usage: \033[1;35m ./src/hw ${test file name} \033[0m"
                  << std::endl;
        std::cerr << "Example: \033[1;36m ./src/hw ../test/tests/test.txt \033[0m"
                  << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream input(argv[1]);

    // const int32_t cores = static_cast<int32_t>(sysconf(_SC_NPROCESSORS_ONLN));

    if (input.is_open()) {
        MapMatrix matrix(0, 0);

        std::string line;

        auto i = 0;
        while (std::getline(input, line)) {
            matrix.AddLine(line, i);
            ++i;
        }
        input.close();

        std::cout << matrix << std::endl;

        matrix.Traverse(0, 0);

        matrix.OutputAreas();

        std::cout << "\033[1;32mMax area is:\033[0m " << matrix.GetMaxArea() << std::endl;
    }

    else {
        std::cout << "\033[1;31m[ERROR]\033[0m Unable to open file."
                  << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}