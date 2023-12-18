#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class GameWindow{
    public:
        int WIDTH, HEIGHT;
        GLFWwindow* window;     //deleted when 'glfwTerminate()' called

        GameWindow();
        void gameLoop();
        void processInputs();
        void enableWiremode();
        ~GameWindow();
};

#endif