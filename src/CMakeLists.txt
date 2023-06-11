cmake_minimum_required(VERSION 3.0.0)

add_executable(27_1_elf_village main.cpp ${MY_INCLUDE_DIR}/branch.h branch.cpp)

target_include_directories(27_1_elf_village PUBLIC ${MY_INCLUDE_DIR})