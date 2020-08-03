#include "Object.h"
#include <GL/glew.h>
#include <string>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

namespace MAGE {
    Object::Object(std::vector<float> _vertices) : vertices(_vertices) {
        Position = glm::vec3(0.0f);
        Rotation = glm::vec3(0.0f);
        Scale = glm::vec3(1.0f);
        Momentum = glm::vec3(0.0f);
        Inertia = 10.0f;
        Gravity = glm::vec3(0.0f, -1.5f, 0.0f);
        CapsuleRadius = 1.0f;
    }

    void Object::GenBuffers(int indexSize) {
        bufferSize = indexSize;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    }

    void Object::SetVertexAttrib(int index, unsigned int type, int size, int stride, int offset) {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(index, size, type, GL_FALSE, stride, (void*)offset);
        glEnableVertexAttribArray(index);
    }

    void Object::Draw() {

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glUseProgram(program);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, bufferSize);
    }
    /*void TexturedObject::Draw() {
        Object::Draw();
        texture.Bind();
    }
    TexturedObject::TexturedObject(Texture texture, std::vector<float> vertices) : Object(vertices), texture(texture) {  }*/

    void Object::BindProgram(unsigned int _program) {
        program = _program;
    }

    void Object::SetUniformM4(const std::string& name, glm::mat4 matrix) {
        glUniformMatrix4fv(glGetUniformLocation(program, name.data()), 1, GL_FALSE, glm::value_ptr(matrix));
    }

    glm::mat4 Object::GetTransform() {
        glm::mat4 translation = glm::translate(glm::mat4(1.0f), Position);
        glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 rotationZ = glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

        glm::mat4 scale = glm::scale(glm::mat4(1.0f), Scale);

        //glm::mat4 view = glm::perspective(glm::radians(45.0f), 16.0f/9.0f, 0.1f, 100.0f);

        return translation * rotationX * rotationY * rotationZ * scale;// * view;
    };

    void Object::ApplyForce(glm::vec3 f) {
        Momentum=f;
    }

    void Object::TickMovement(float deltaTime) {
        Position+=Momentum*deltaTime;
        Position+=Gravity*deltaTime;

        Momentum*=0.9f;
    }
}
