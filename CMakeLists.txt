cmake_minimum_required(VERSION 3.16.3)

project(OLAS VERSION 1.0)

add_executable(${PROJECT_NAME} main.cpp)

# adder use logic
option(USE_ADDER "A simple library for adding two floats" ON)
if(USE_ADDER)
  add_subdirectory(adder)

  list(APPEND EXTRA_LIBS "adder")
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/adder")
  list(APPEND EXTRA_LINK_DIRS "adder")

endif()

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_BINARY_DIR}
)

configure_file(OLASConfig.h.in OLASConfig.h)

# download all submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
  # update submodules as needed
  option(GIT_SUBMODULE "Check submodules during build" ON)
  if(GIT_SUBMODULE)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT
    )
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules manually")
    endif()
  endif()
endif()

# check all the submodules
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
  message(FATAL_ERROR "The glfw submodule was not downloaded! GIT_SUBMODULE was either turned OFF or failed. Please download glfw submodule.")
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
PRIVATE
  external/glfw/include
  ${EXTRA_INCLUDES}
)

target_link_directories(${PROJECT_NAME}
  PRIVATE
    external/glfw/src
    ${EXTRA_LINK_DIRS}
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
  glfw
  ${EXTRA_LIBS}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/OLASConfig.h" DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERISON_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)
