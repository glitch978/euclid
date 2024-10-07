#pragma once

#include <string>
#include "util/concept.hpp"
#include "util/types.h"

namespace gfx {
    enum Shader_Type {
        VERTEX = 35633,
        FRAGMENT = 35632,
        COMPUTE = 37305,
    };

    struct Shader {
        std::string path;
        Shader_Type type;

        u32 gl_shader;

        Shader() = default;
        Shader(const char* path) : path(path) {};
        Shader(const char* path, bool init) : path(path) {
            if (init) this->gl_init();
        };

        ~Shader();

        void gl_init();
        void gl_delete();
 
        private:
        std::string gl_shader_source;
    };

}
