#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "world.h"
#include "renderers.h"

enum GameOption {
    WIREMODE,
};

class GameWindow{
    public:
        int WIDTH, HEIGHT;
        GLFWwindow* window;     //deleted when 'glfwTerminate()' called
        World world;

        GameWindow();
        void gameLoop();
        void processInputs();
        void renderAll();
        void enableGameOption(GameOption);
        ~GameWindow();
};


#endif