#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>

#include <iostream>

using namespace std;

//NOTE: Needs to be include to catch/callback errors
void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

int main() {

    //Callback all errors during and after run time
    glfwSetErrorCallback(error_callback);

    GLFWallocator allocator;
    allocator.allocate = my_malloc;
    allocator.reallocate = my_realloc;
    allocator.deallocate = my_free;
    allocator.user = NULL;
 
glfwInitAllocator(&allocator);
    // Initialize GLFW
    if (!glfwInit())
    {
        return -1;
    }
    
    //Checking which windows-server we use (X11)
    if (glfwPlatformSupported(GLFW_PLATFORM_X11)) {
        cout << "initializing " << glfwGetPlatform() << " enviroment " << endl;
        glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
    } else return -1;

    // Create a window
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Game Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Main game loop
    while (!glfwWindowShouldClose(window))
    {
        // Input handling
        glfwPollEvents();

        // Rendering code goes here

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Clean up
    glfwTerminate();

    return 0;
}
