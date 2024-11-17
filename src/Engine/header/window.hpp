#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLFW/glfw3.h>

// Default dimensions for the window
static constexpr int WINDOWHEIGHT = 800;
static constexpr int WINDOWWIDTH = 600;


class Window {
public:
    virtual void InitializeWindow();
    virtual void OpenWindow();
    virtual void WindowSettings();

    // Getter methods
    int GetHeight() const {
        return height;
    }
    int GetWidth() const {
        return width;
    }

    // Setter methods
    void SetHeight(int height) {
        this->height = height;
    }
    void SetWidth(int width) {
        this->width = width;
    }
    virtual ~Window(); // Virtual destructor for proper cleanup
private:
    GLFWwindow* window = nullptr;  // Pointer to the GLFW window
    int height = WINDOWHEIGHT;    // Default height
    int width = WINDOWWIDTH;      // Default width
    bool isOpen = false;          // Window open state

};



#endif
