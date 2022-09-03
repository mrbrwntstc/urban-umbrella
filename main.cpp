#include <iostream>

#include "adder.h"

#include "GLFW/glfw3.h"

#include "OLASConfig.h"

int main(int argc, char* argv[])
{
  std::cout << "Hey, Zeus!" << std::endl;
  std::cout << add(72.1f, 73.0f) << std::endl;

  std::cout << argv[0] << " Version " << OLAS_VERSION_MAJOR << "." << OLAS_VERSION_MINOR << std::endl;

  GLFWwindow *window;
  if(glfwInit() == GLFW_FALSE)
  {
    fprintf(stderr, "Failed to initialize GLFW\n");
    exit(EXIT_FAILURE);
  }

  window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);
  if(!window)
  {
    fprintf(stderr, "Failed to open GLFW window\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // main loop
  while(!glfwWindowShouldClose(window))
  {

    // swap buffers
    glfwSwapBuffers(window);
    
    // poll for I/O events
    glfwPollEvents();
  }

  // exit GLFW
  glfwTerminate();

  return 0;
}