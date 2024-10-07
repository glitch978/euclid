#pragma once

#include "GLFW/glfw3.h"

namespace platform::glfw {
    void error_callback(int err, const char *msg);

    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    void framebuffer_size_callback(GLFWwindow *window, int width, int height);
}
