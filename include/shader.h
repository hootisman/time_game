#ifndef SHADER_H
#define SHADER_H

#include <filesystem>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
// #include <vector>
#include "log.h"


class ShaderProgram{
private:
    unsigned int initShader(std::string, GLenum);
public:
    unsigned int id;
    // std::vector<unsigned int> shaders;

    ShaderProgram();
    // void addShader(std::string, GLenum);
    // void attachShaders();
    // void deleteShaders();
    void use();
};
#endif