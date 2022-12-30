cmake_minimum_required(VERSION 3.23)
project(BomManager)

set(CMAKE_CXX_STANDARD 98)

add_executable(BomManager main.c lib/menu.h lib/menu.c lib/types.h lib/part.c lib/part.h lib/formula.c lib/formula.h lib/partCount.c lib/partCount.h lib/utils.c lib/utils.h)
