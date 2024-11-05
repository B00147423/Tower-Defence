cmake_minimum_required(VERSION 3.10)
project(TowerDefenseGame)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    # Use Multi-threaded DLL runtime
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD")
    
    # Ignore conflicting default libraries to resolve LNK4098 warning
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib")
endif()

# Set paths for precompiled GLFW library
set(GLFW_LIB_DIR "${CMAKE_SOURCE_DIR}/libs/glfw-3.4.bin.WIN64/lib-vc2022")
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/glfw-3.4.bin.WIN64/include")

# Include directories for GLAD, GLFW, and GLM
include_directories(${GLFW_INCLUDE_DIR})
include_directories(libs/glad/include)
include_directories(libs/glm-master)

# Link directory for GLFW
link_directories(${GLFW_LIB_DIR})

# Add GLAD source file explicitly
set(SOURCES src/main.cpp libs/glad/src/glad.c)

# Create the executable and link necessary libraries
add_executable(TowerDefenseGame ${SOURCES})
target_link_libraries(TowerDefenseGame glfw3 opengl32)
