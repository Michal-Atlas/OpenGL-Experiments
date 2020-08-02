#include "Texture.h"
#include <GL/glew.h>
#include <stb/stb_image.h>

namespace MAGE {
    Texture::Texture(const char *filePath) {
        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        unsigned char *data = stbi_load((filePath), &width, &height, &nrChannels, 0);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateTextureMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }
    void Texture::Bind(){
        glBindTexture(GL_TEXTURE_2D, ID);
    }
}
