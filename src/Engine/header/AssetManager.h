// AssetManager.h
#pragma once
#include <unordered_map>
#include <string>
#include <glad/glad.h>

class AssetManager {
public:
    GLuint loadTexture(const std::string& filePath);
    GLuint getTexture(const std::string& filePath);

private:
    std::unordered_map<std::string, GLuint> textures;
};
