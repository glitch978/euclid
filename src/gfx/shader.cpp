#include <fstream>
#include <sstream>
#include <map>
#include <string.h>

#include "glad/glad.h"
#include "logc/log.h"
#include "gfx/shader.hpp"
#include "util/string.hpp"

std::map<std::string, gfx::Shader_Type> shader_type_string_map = {
    { "vs", gfx::Shader_Type::VERTEX },
    { "fs", gfx::Shader_Type::FRAGMENT },
    { "cs", gfx::Shader_Type::COMPUTE }
};

void gfx::Shader::gl_init() {
    const char* path = this->path.c_str();

    std::ifstream in(path);
    std::stringstream buffer;
    buffer << in.rdbuf();

    if (buffer.peek() == 0) {
        log_error("Euclid: Failed to read %s", path);
        return;
    }

    std::string shader_str = buffer.str();
    const char* shader_source = util::to_cstr(shader_str);
    
    std::vector<std::string> tks = util::ssplit(path, ".");
    std::string ext = tks.back();
    this->type = shader_type_string_map[ext];

    u32 gl_shader = glCreateShader(this->type);
    glShaderSource(gl_shader, 1, &shader_source, NULL);
    glCompileShader(gl_shader);

    int success;
    char infolog[512];
    glGetShaderiv(gl_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(gl_shader, 512, NULL, infolog);
        log_error("Euclid: Error Compiling %s - %s", path, infolog);
        return;
    } else
        log_info("Euclid: Successfully compiled %s", path);

    this->gl_shader = gl_shader;
}

void gfx::Shader::gl_delete() {
    glDeleteShader(this->gl_shader);
    log_info("Euclid: Deleted shader %s", this->path.c_str());
}

gfx::Shader::~Shader() {
    if (this->gl_shader != 0) {
        glDeleteShader(this->gl_shader);
    }
}
