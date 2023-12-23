#ifndef LOG_H
#define LOG_H

#include <string>
#include <iostream>
#include <glad/glad.h>

class Logger{
public:
    static void error(std::string);
    static void checkGLResult(int, GLenum);
};

extern Logger LOGGER;

#endif