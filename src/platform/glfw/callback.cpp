#include <string.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "logc/log.h"

#include "platform/glfw/callback.hpp"
#include "util/types.h"

void platform::glfw::error_callback(int err, const char *msg) {
    log_error("Euclid - GLFW Error(%i) %s", err, msg);
}

void platform::glfw::key_callback(
    GLFWwindow *window, int key, int scancode, int action, UNUSED int mods) {
    
    const char *key_name = glfwGetKeyName(key, scancode);
    
    if (action == GLFW_PRESS) {
        //log_info("%s pressed", key_name);
    } else if (action == GLFW_RELEASE) {

        if (strcmp(key_name, "w") == 0 ) { // segfaults when strcmping GLFW_UNKOWN_KEY or whatever it is. 
                                           // fix is adding an extra step that compares the keycode to a map of known keys so as to ensure that there isnt an unknown key
            int polygon_mode[2];
            glGetIntegerv(GL_POLYGON_MODE, polygon_mode);
            
            if (polygon_mode[0] == GL_LINE) {
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                log_info("Euclid: Fill Mode");
            } else {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                log_info("Euclid: Wireframe Mode");
            }
        }
    }
}

void platform::glfw::framebuffer_size_callback(
    GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
