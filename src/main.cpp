#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3.h>
#include <windows.h>
#include <string>
//#include "FilePicker.cpp"
#include "./Engine/header/window.hpp"

int main() {
    {
        Window myWindow;
        myWindow.InitializeWindow(); 
        myWindow.OpenWindow();
    } 
    return 0;
}



//// Callback function for handling mouse clicks
//static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
//    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
//        // Get the mouse position
//        double xpos, ypos;
//        glfwGetCursorPos(window, &xpos, &ypos);
//
//        // Convert screen coordinates to OpenGL coordinates
//        int width, height;
//        glfwGetWindowSize(window, &width, &height);
//        float x = xpos / width * 2 - 1;
//        float y = 1 - ypos / height * 2;
//
//        // Check if the mouse is inside the button bounds
//        if (x >= BUTTON_RECT.x1 && x <= BUTTON_RECT.x2 && y >= BUTTON_RECT.y1 && y <= BUTTON_RECT.y2) {
//            // Open file picker dialog every time the button is clicked
//            std::wstring filePath = openFilePicker();
//
//            if (!filePath.empty()) {
//                std::wcout << L"Selected file: " << filePath << std::endl;
//            }
//            else {
//                std::wcout << L"No file selected." << std::endl;
//            }
//        }
//    }
//}
//
//int main() {
//    if (!glfwInit()) return -1;
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL File Picker Button", NULL, NULL);
//    if (!window) {
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//
//    // Set the mouse callback function
//    glfwSetMouseButtonCallback(window, mouse_button_callback);
//
//    while (!glfwWindowShouldClose(window)) {
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // Render the button (a rectangle)
//        glColor3f(BUTTON_COLOR.r, BUTTON_COLOR.g, BUTTON_COLOR.b); // Set button color
//
//        glBegin(GL_QUADS); // Draw the button
//        glVertex2f(BUTTON_RECT.x1, BUTTON_RECT.y1); // Bottom-left corner
//        glVertex2f(BUTTON_RECT.x2, BUTTON_RECT.y1); // Bottom-right corner
//        glVertex2f(BUTTON_RECT.x2, BUTTON_RECT.y2); // Top-right corner
//        glVertex2f(BUTTON_RECT.x1, BUTTON_RECT.y2); // Top-left corner
//        glEnd();
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
//    return 0;
//}