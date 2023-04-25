cmake_minimum_required(VERSION 3.25)
project(letcode)

set(CMAKE_CXX_STANDARD 14)

include_directories("1609. Even Odd Tree")

add_executable(letcode
        "100. Same Tree/Solution.c"
        "100. Same Tree/Solution.cpp"
        "101. Symmetric Tree/Solution.c"
        "110. Balanced Binary Tree/Solution.cpp"
        "1609. Even Odd Tree/Solution.cpp"
        "1609. Even Odd Tree/Solution.h"
        "37. Sudoku Solver/Solution.cpp"
        "733. Flood Fill/Solution.cpp"
        "965. Univalued Binary Tree/Solution.cpp"
        "Palindrome Number/Solution.c"
        Test/test.c "1609. Even Odd Tree/Main.cpp")
