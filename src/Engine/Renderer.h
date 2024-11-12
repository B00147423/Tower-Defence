#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Renderer {
public:
    Renderer() : shaderProgram(0), VAO(0), VBO(0), EBO(0) {}
    void init();
    void drawTexturedQuad(GLuint texture, glm::vec2 position, glm::vec2 size);  // Declaration of drawTexturedQuad
    void drawFullScreenQuad(GLuint texture);  // Declaration of drawFullScreenQuad
    void clear() const;
    void display() const;

private:
    GLuint shaderProgram;
    GLuint VAO, VBO, EBO;
};
