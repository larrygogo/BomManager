cmake_minimum_required(VERSION 3.23)
project(BomManager)

set(CMAKE_CXX_STANDARD 98)

add_executable(BomManager main.c core/menu.h core/menu.c core/types.h core/part.c core/part.h core/formula.c core/formula.h core/partCount.c core/partCount.h core/utils.c core/utils.h)
