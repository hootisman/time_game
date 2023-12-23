#include "../include/window.h"

int main() {
    GameWindow game; 
    game.gameLoop();   //the game basically
    glfwTerminate();
    return 0;
}
