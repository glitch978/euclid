#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "logc/log.h"

#include "util/types.h"
#include "platform/glfw/callback.hpp"

#include "gfx/init.hpp"
#include "gfx/window.hpp"


void gfx::Window::init(u16 window_width, u16 window_height) {
    glfwSetErrorCallback(platform::glfw::error_callback);

    if (!glfwInit()) 
        log_fatal("Euclid: GLFW(%i) - Initialization Error", glfwGetError(NULL));

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(
        window_width, window_height,
        "Euclid", NULL, NULL);

    if (!this->window)
        log_fatal("Euclid: GLFW(%i) - Error Creating Window", glfwGetError(NULL));
    
    glfwMakeContextCurrent(this->window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
        log_fatal("Euclid: GLAD Initialization Error");
   
    // set window obj size to current glfw window size
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    this->window_size.x = width;
    this->window_size.y = height;

    glViewport(0, 0, width, height);

    glfwSetKeyCallback(this->window, platform::glfw::key_callback);
}
