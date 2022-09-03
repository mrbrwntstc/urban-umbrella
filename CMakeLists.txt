cmake_minimum_required(VERSION 3.16.3)

project(OLAS)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(adder)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
PRIVATE
  adder
  external/glfw/include
)

target_link_directories(${PROJECT_NAME}
  PRIVATE
    adder
    external/glfw/src
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
  adder
  glfw
)
