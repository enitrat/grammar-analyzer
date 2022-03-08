cmake_minimum_required(VERSION 3.21)
project(Lexer)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Lexer
        lexer.cpp
        lexer.h
        main.cpp
        symbole.cpp
        symbole.h state.h automate.cpp automate.h state.cpp)
