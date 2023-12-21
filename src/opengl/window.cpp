#include <iostream>
#include "../../include/window.h"

GameWindow::GameWindow() {
    this->WIDTH = 800;
    this->HEIGHT = 600;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //loads GLFW window
    this->window = glfwCreateWindow(this->WIDTH, this->HEIGHT, "t i m e", NULL, NULL);  
    if (this->window == NULL) {
        std::cout << "Failed to load window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(this->window);
    //loads GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to init GLAD" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    //callback function for when window is resized
    glfwSetFramebufferSizeCallback(this->window, [](GLFWwindow* window, int width, int height){ 
        std::cout << "width: " << width << " height: " << height << std::endl;
        glViewport(0,0,width,height);
    });

    glEnable(GL_DEPTH_TEST);    //for depth buffer
    this->enableGameOption(GameOption::WIREMODE);       //enables wiremode
}
void GameWindow::gameLoop(){
    while (!glfwWindowShouldClose(window)){
        this->processInputs();

        glClearColor(0.1f, 0.5f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void GameWindow::processInputs(){
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE)){
        glfwSetWindowShouldClose(this->window, true);
    }
    
}
void GameWindow::enableGameOption(GameOption option){
    switch (option){
    case WIREMODE:
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        break;
    
    default:
        break;
    }
}
GameWindow::~GameWindow(){
    glfwTerminate();
}