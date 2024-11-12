#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "./Engine/Renderer.h"
#include "./Engine/AssetManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Helper function to read shader code from a file
std::string readShaderFile(const char* filePath) {
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath) {
    std::string vertexCode = readShaderFile(vertexPath);
    const char* vShaderCode = vertexCode.c_str();

    std::string fragmentCode = readShaderFile(fragmentPath);
    const char* fShaderCode = fragmentCode.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

int main() {
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Full-Screen Texture", NULL, NULL);
    if (!window) {
        cerr << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cerr << "Failed to initialize GLAD" << endl;
        return -1;
    }

    Renderer renderer;
    renderer.init();

    // Assuming AssetManager handles texture loading
    AssetManager assetManager;
    GLuint texture = assetManager.loadTexture("C:/Users/beka/Tower-Defence/src/map2.png");
    if (texture == 0) {
        cerr << "Failed to load texture." << endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        renderer.clear();

        // Draw the full-screen quad
        renderer.drawFullScreenQuad(texture);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
