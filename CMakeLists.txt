cmake_minimum_required(VERSION 3.13)
project(COMPILATION_EDEMANN_FLEGON C)

set(CMAKE_C_STANDARD 99)

add_executable(COMPILATION_EDEMANN_FLEGON main.c analyseurLexical.c analyseurLexical.h tableDesIdentificateurs.c tableDesIdentificateurs.h)