// #include "header/loadTexture.h"
// #include <iostream>
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>

// GLuint loadTexture(const char* path) {
//     GLuint textureID;
//     glGenTextures(1, &textureID);

//     int width, height, nrChannels;
//     unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0); // `stb_image.h` is already compiled elsewhere
//     if (data) {
//         GLenum format = nrChannels == 3 ? GL_RGB : GL_RGBA;
//         glBindTexture(GL_TEXTURE_2D, textureID);
//         glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);

//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//     } else {
//         std::cerr << "Failed to load texture: " << path << std::endl;
//     }
//     stbi_image_free(data);
//     return textureID;
// }
