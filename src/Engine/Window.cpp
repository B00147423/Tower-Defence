#include <iostream>
#include "header/window.hpp"

void Window::InitializeWindow() {
    if (!glfwInit()) {
        std::cerr << "GLFW Failed to Initialize" << std::endl;
        return;
    }

    window = glfwCreateWindow(width, height, "My Window", nullptr, nullptr);
    if (!window) {
        std::cerr << "Window Failed to Open" << std::endl;
        glfwTerminate();
        return;
    }
    std::cout << "Window Created Successfully" << std::endl;
    isOpen = true;
}

void Window::OpenWindow() {
    if (!window) {
        std::cerr << "Window not created. Cannot open." << std::endl;
        return;
    }

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    isOpen = false;
}

void Window::WindowSettings() {
    if (!window) {
        std::cerr << "Window not created. Cannot apply settings." << std::endl;
        return;
    }

    // Add custom window settings here
    std::cout << "Window settings applied" << std::endl;
}

Window::~Window() {
    if (window) {
        glfwDestroyWindow(window);
        std::cout << "Window destroyed successfully." << std::endl;
    }
    else {
        std::cout << "No window to destroy." << std::endl;
    }
    glfwTerminate();
    std::cout << "GLFW terminated successfully." << std::endl;
}