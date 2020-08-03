#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace MAGE {
    GLFWwindow *Init(int width, int height, const char *title) {
        GLFWwindow *window;
        glfwInit();
        glfwSwapInterval(1);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        glfwMakeContextCurrent(window);
        glewInit();
        return window;
    }
}