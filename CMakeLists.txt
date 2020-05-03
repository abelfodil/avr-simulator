set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_C_COMPILER_WORKS 1)

set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_CXX_COMPILER_WORKS 1)

project(assignment)
cmake_minimum_required(VERSION 3.11)

file(GLOB SRC_C ${CMAKE_SOURCE_DIR}/*.c)
file(GLOB SRC_CXX ${CMAKE_SOURCE_DIR}/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_C} ${SRC_CXX})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -mmcu=atmega324pa -Wl,--undefined=_mmcu,--section-start=.mmcu=0x000000 -I/usr/include)

set(INPUT_WAVE "${CMAKE_SOURCE_DIR}/input.vcd")
set(EXEC_PATH "${PROJECT_BINARY_DIR}/${PROJECT_NAME}")
add_custom_target(simulate COMMAND simavr -t -i ${INPUT_WAVE} ${EXEC_PATH} -v -v -v -v -v -v -v -v)
add_dependencies(simulate ${PROJECT_NAME})
