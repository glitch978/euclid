#pragma once 

#include "glad/glad.h"
#include "logc/log.h"
#include "gfx/shader.hpp"

namespace gfx {
template <is_all_same<gfx::Shader>... Args>
    u32 create_gl_program(u8 id, Args... args) {
        u32 program = glCreateProgram();
        for (auto s : {args...}) {
            glAttachShader(program, s.gl_shader);
        }
        
        glLinkProgram(program);

        int success;
        char infolog[512];
        glGetProgramiv(program, GL_LINK_STATUS, &success);
    
        if (!success) {
            glGetProgramInfoLog(program, 512, NULL, infolog);
            log_error("Euclid: Error linking shader program %i - %s", id, infolog);
            return 1;
        } else 
            log_info("Euclid: Successfully linked shader program %i", id);

        return program;
    }
}
