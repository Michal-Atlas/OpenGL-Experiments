#include "Object.h"
#include <GL/glew.h>

namespace MAGE {
    Object::Object(std::vector<float> _vertices) : vertices(_vertices) {}

    void Object::GenBuffers(int indexSize) {
        bufferSize = indexSize;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    }

    void Object::SetVertexAttrib(int index, unsigned int type, int size, int stride, int offset) {
        glVertexAttribPointer(index, size, type, GL_FALSE, stride, (void *) offset);
        glEnableVertexAttribArray(index);
    }

    void Object::Draw() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, bufferSize);
    }
}
