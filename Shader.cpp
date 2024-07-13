#include <iostream>
#include "Shader.h"
#include <GL/glew.h>

namespace MAGE {
    bool Shader::AddComponent(unsigned int type, char *source) {
        int shaderId = glCreateShader(type);
        glShaderSource(shaderId, 1, &source, nullptr);
        glCompileShader(shaderId);

        int success;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
        if (!success) {
            int length;
            glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
            char message[length];
            glGetShaderInfoLog(shaderId, length, &length, message);
            std::cout << "Shader Error [" << type << "]: " << message << std::endl;
            return -1;
        };
        glAttachShader(ID, shaderId);
        glDeleteShader(shaderId);
        return 0;
    }

    void Shader::Compile() {
        glLinkProgram(ID);
    }

    Shader::Shader() {
        ID = glCreateProgram();
    }
}
