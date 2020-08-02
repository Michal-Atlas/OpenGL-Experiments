#ifndef MAGE_OBJECT_H
#define MAGE_OBJECT_H

#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <tuple>
#include "Texture.h"

namespace MAGE {
    class Object {
    public:
        glm::vec3 Position;
        glm::vec3 Rotation;
        glm::vec3 Scale;
        glm::vec3 Gravity;
        std::vector<float> vertices;
        float CapsuleRadius;

        Object(std::vector<float> _vertices);

        void GenBuffers(int indexSize);

        void SetVertexAttrib(int index, unsigned int type, int size, int stride, int offset);

        void Draw();

        void BindProgram(unsigned int program);

        void SetUniformM4(const std::string& name, glm::mat4 matrix);

        glm::mat4 GetTransform();

        void ApplyForce(glm::vec3 f);
        float Inertia;
        glm::vec3 Momentum;
        void TickMovement(float deltaTime);

    private:
        int bufferSize;
        int program;
        unsigned int VBO, VAO;
    };

    class TexturedObject : public Object{
    public:
        Texture texture;
        TexturedObject(Texture texture, std::vector<float> vertices);
        void Draw();
    };
    class IndexedObject : Object{

    };
    class IndexedTexturedObject : TexturedObject, IndexedObject{

    };
}


#endif //MAGE_OBJECT_H
