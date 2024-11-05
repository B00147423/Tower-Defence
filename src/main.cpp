//C:\Users\beka\Tower-Defence\src\main.cpp
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size(GLFWwindow* window, int width, int height){
    // Sets the OpenGL viewport to cover the whole window
    glViewport(0,0,width,height);
}
int main() {
    if(!glfwInit()){
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    // set the version of opengl to use
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    

    //creatign window mdoe indow glfw
    GLFWwindow* window = glfwCreateWindow(800,800, "First window opengl", nullptr, nullptr);
    //make the window context current
    glfwMakeContextCurrent(window);
    // Load OpenGL functions using GLAD
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Faield to initialize glad "<< std::endl;
        return -1;
    }

    //set the intial viewport to cove rthe whole window
    glViewport(0, 0, 600, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size);

    while(!glfwWindowShouldClose(window)){
        //ckear the screeen to cov er (let's use a nice blue here)

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //swap thje frot and back buffers (udpate win dow with color)
        glfwSwapBuffers(window);
        glfwPollEvents(); // poll for and process event

        //clean up and exit
    }

    glfwTerminate();
    return 0;
}