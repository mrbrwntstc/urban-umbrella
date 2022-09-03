cmake_minimum_required(VERSION 3.16.3)

project(OLAS)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(adder)

target_include_directories(${PROJECT_NAME}
PRIVATE
  adder
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
  adder
)
