// Copyright 2021 DPeshkoff;
// Distributed under the GNU General Public License, Version 3.0. (See
// accompanying file LICENSE)

#include <gtest/gtest.h>

#include <fstream>

#include "field.h"

TEST(test0_test, test0_test) {
    std::ifstream input("../test/tests/test0.txt");

    ASSERT_TRUE(input.is_open());

    MapMatrix matrix(0, 0);

    std::string line;

    auto i = 0;
    while (std::getline(input, line)) {
        matrix.AddLine(line, i);
        ++i;
    }
    input.close();

    matrix.Traverse(0, 0);

    EXPECT_EQ(matrix.GetMaxArea(), 6);
}

TEST(test1_test, test1_test) {
    std::ifstream input("../test/tests/test1.txt");

    ASSERT_TRUE(input.is_open());

    MapMatrix matrix(0, 0);

    std::string line;

    auto i = 0;
    while (std::getline(input, line)) {
        matrix.AddLine(line, i);
        ++i;
    }
    input.close();

    matrix.Traverse(0, 0);

    EXPECT_EQ(matrix.GetMaxArea(), 27);
}


TEST(test2_test, test2_test) {
    std::ifstream input("../test/tests/test2.txt");

    ASSERT_TRUE(input.is_open());

    MapMatrix matrix(0, 0);

    std::string line;

    auto i = 0;
    while (std::getline(input, line)) {
        matrix.AddLine(line, i);
        ++i;
    }
    input.close();

    matrix.Traverse(0, 0);

    EXPECT_EQ(matrix.GetMaxArea(), 10);
}
