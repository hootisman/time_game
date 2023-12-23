#include "../include/log.h"

Logger LOGGER;

void Logger::error(std::string msg){
    std::cout << "ERROR: " << msg << std::endl;
}

void Logger::checkGLResult(int success, GLenum type){
    if (success) return;
    
    std::string msg = "";
    switch (type)
    {
    case GL_COMPILE_STATUS:
        msg = "Failed to compile shader!";
        break;
    
    case GL_LINK_STATUS:
        msg = "Failed to link shaders!";
        break;
    
    default:
        break;
    }
    if(!(msg == "")) Logger::error(msg);
}