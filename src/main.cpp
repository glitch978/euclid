#include "logc/log.h"

#include "gfx/window.hpp"
#include "gfx/shader.hpp"
#include "gfx/program.hpp"
#include "util/types.h"

float vertices[] = {
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f
};  

u32 indicies[] = {
    2, 1, 3,
    1, 2, 3,
};

int main(void) {
    gfx::Window window = gfx::Window();
    window.init(512, 512);

    gfx::Shader vert = gfx::Shader("res/glsl/triangle.vs", true);
    gfx::Shader frag = gfx::Shader("res/glsl/triangle.fs", true);

    u32 program = gfx::create_gl_program(1, vert, frag);
    glUseProgram(program);

    vert.gl_delete();
    frag.gl_delete();

    u32 VBO, VAO, EBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO); // copy vertices into a buffer for OpenGL
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);
    
    // set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window.window)) {
        glfwSwapBuffers(window.window);
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        //window.handle_resize();
    }

    glfwTerminate();
    return 0;
}
