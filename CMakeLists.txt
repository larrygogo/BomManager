cmake_minimum_required(VERSION 3.23)
project(BomManager)

set(CMAKE_CXX_STANDARD 98)

add_executable(BomManager main.c include/BOMMenu.h core/BOMMenu.c include/BOMTypes.h core/BOMPart.c include/BOMPart.h core/BOMFormula.c include/BOMFormula.h core/BOMPartCount.c include/BOMPartCount.h core/BOMUtils.c include/BOMUtils.h)
