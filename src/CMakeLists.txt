cmake_minimum_required(VERSION 3.21)
project(Lexer)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(Lexer
        lexer.cpp
        lexer.h
        main.cpp
        symbole.cpp
        symbole.h State.h Axiome.cpp Automate.cpp Automate.h State.cpp)
