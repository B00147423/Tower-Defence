cmake_minimum_required(VERSION 3.10)
project(TowerDefenseGame)

set(CMAKE_CXX_STANDARD 17)

# Set compiler-specific flags for MSVC
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:libvcruntime.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcpmt.lib /NODEFAULTLIB:libcpmtd.lib")
endif()

# Set paths for precompiled GLFW library
set(GLFW_LIB_DIR "${CMAKE_SOURCE_DIR}/libs/glfw-3.4.bin.WIN64/lib-vc2022")
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/glfw-3.4.bin.WIN64/include")

# Include directories for GLAD, GLFW, GLM, stb_image, and ImGui
include_directories(${GLFW_INCLUDE_DIR})
include_directories("${CMAKE_SOURCE_DIR}/libs/glad/include")
include_directories("${CMAKE_SOURCE_DIR}/libs/glm-master")
include_directories("${CMAKE_SOURCE_DIR}/libs")  # Directory for stb_image.h
include_directories("${CMAKE_SOURCE_DIR}/imgui")  # Directory for ImGui
include_directories("${CMAKE_SOURCE_DIR}/src")  
include_directories("${CMAKE_SOURCE_DIR}/src/Engine")  # Corrected to src/Engine

# Link directory for GLFW
link_directories(${GLFW_LIB_DIR})

# Add all source files in src/Engine explicitly
set(SOURCES 
    src/main.cpp 
    src/Engine/AssetManager.cpp
    src/Engine/Audio.cpp
    src/Engine/Component.cpp
    src/Engine/Entity.cpp
    src/Engine/Input.cpp
    src/Engine/Physics.cpp
    src/Engine/Renderer.cpp
    src/Engine/Scene.cpp
    src/Engine/Shader.cpp
    src/Engine/Timer.cpp
    src/Engine/UIElements.cpp
    src/Engine/Window.cpp
    libs/glad/src/glad.c
)
# Add ImGui source files
add_library(imgui STATIC
    ${PROJECT_SOURCE_DIR}/imgui/imgui.cpp
    ${PROJECT_SOURCE_DIR}/imgui/imgui_draw.cpp
    ${PROJECT_SOURCE_DIR}/imgui/imgui_widgets.cpp
    ${PROJECT_SOURCE_DIR}/imgui/imgui_tables.cpp
    ${PROJECT_SOURCE_DIR}/imgui/backends/imgui_impl_glfw.cpp
    ${PROJECT_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp
)

# Create the executable and link necessary libraries
add_executable(TowerDefenseGame ${SOURCES})

# Link imgui, glfw, and OpenGL libraries to the main executable
target_link_libraries(TowerDefenseGame imgui glfw3 opengl32)

# Set the working directory for debugging in Visual Studio
set_property(TARGET TowerDefenseGame PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/src")
