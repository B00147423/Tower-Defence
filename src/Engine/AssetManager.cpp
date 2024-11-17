// #define STB_IMAGE_IMPLEMENTATION
// #include "header/AssetManager.h"
// #include <stb_image.h>
// #include <iostream>
// #include "string"
// using namespace std;

// GLuint AssetManager::loadTexture(const string& filePath) {
//     if (textures.find(filePath) != textures.end()) {
//         return textures[filePath];
//     }
//     stbi_set_flip_vertically_on_load(true);
//     int width, height, channels;
//     unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &channels, STBI_rgb_alpha);  // Force RGBA

//     if (!data) {
//         cerr << "Failed to load texture: " << filePath << " - Error: " << stbi_failure_reason() << endl;
//         return 0;
//     }
//     cout << "Texture loaded from file: " << filePath << endl;

//     // Generate and bind texture
//     GLuint textureID;
//     glGenTextures(1, &textureID);
//     glBindTexture(GL_TEXTURE_2D, textureID);
//     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//     glGenerateMipmap(GL_TEXTURE_2D);

//     // Set texture parameters
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     stbi_image_free(data);

//         // Check for any OpenGL errors after loading and binding the texture
//     GLenum error = glGetError();
//     if (error != GL_NO_ERROR) {
//         cerr << "OpenGL error after loading texture: " << error << endl;
//     }
//     textures[filePath] = textureID;

//     return textureID;
// }

// GLuint AssetManager::getTexture(const string& filePath) {
//     return textures.find(filePath) != textures.end() ? textures[filePath] : loadTexture(filePath);
// }
