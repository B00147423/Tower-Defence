// src/Transform.h
#pragma once  // Use this or the include guard below

#include <glm/glm.hpp>

struct Material {
    GLuint textureID;
};

struct Transform {
    glm::vec2 pos;
    glm::vec2 size;
    Material material;
};
