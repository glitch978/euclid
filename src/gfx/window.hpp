#pragma once

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glm/vec2.hpp"

#include "util/types.h"

namespace gfx {
    struct Window {
        GLFWwindow *window;

        glm::vec2 window_size;

        Window() = default;

        void init(u16 window_width, u16 window_height);

        void handle_resize();
        bool focused();
    };
}
