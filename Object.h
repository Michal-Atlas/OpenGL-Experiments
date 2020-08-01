#ifndef JUMP_OBJECT_H
#define JUMP_OBJECT_H

#include <glm/glm.hpp>
#include <vector>

namespace MAGE {
    class Object {
    public:
        unsigned int VBO, VAO;
        glm::vec3 Position;
        glm::vec3 Rotation;
        std::vector<float> vertices;

        Object(std::vector<float> _vertices);

        void GenBuffers(int indexSize);

        static void SetVertexAttrib(int index, unsigned int type, int size, int stride, int offset);

        void Draw();

        void BindProgram(unsigned int program);

    private:
        int bufferSize;
    };
}

#endif //JUMP_OBJECT_H
