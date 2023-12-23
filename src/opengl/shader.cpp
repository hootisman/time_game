#include "../../include/shader.h"



/* 
    Adds and links shaders to program
*/
ShaderProgram::ShaderProgram(){
    this->id = glCreateProgram();
    // this->shaders;

    // this->addShader("src/shaders/vertexshader.glsl", GL_VERTEX_SHADER);
    // this->addShader("src/shaders/fragshader.glsl", GL_FRAGMENT_SHADER);

    unsigned int vertexShaderId = this->initShader("src/shaders/vertexshader.glsl", GL_VERTEX_SHADER);
    unsigned int fragShaderId = this->initShader("src/shaders/fragshader.glsl", GL_FRAGMENT_SHADER);

    //shader linking time
    // this->attachShaders();
    glLinkProgram(this->id);

    int success;
    glGetProgramiv(this->id, GL_LINK_STATUS, &success);
    Logger::checkGLResult(success, GL_LINK_STATUS);


    // this->deleteShaders();

    //delete shaders
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragShaderId);


}

/* 
    Compiles new shader and returns the id
*/
unsigned int ShaderProgram::initShader(std::string path, GLenum shaderType){
    const char* sourceCode;
    std::ifstream file;
    std::stringstream stream;
    
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        //tries to open and set source code to variable
        file.open(path);            //open file
        stream << file.rdbuf();     //read file
        sourceCode = stream.str().c_str();  //to string
        file.close();
    }catch (std::ifstream::failure e) { LOGGER.error("Failed to read Shader file! At Shader::initShader(" + path + ")\n" + std::string(e.what())); }

    unsigned int shaderId = glCreateShader(shaderType);     //new shader at shaderId
    glShaderSource(shaderId, 1, &sourceCode, NULL);         //set shaderId to reference source code
    glCompileShader(shaderId);                              //attempt compilation

    int success;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    Logger::checkGLResult(success, GL_COMPILE_STATUS);      //prints error if compile failed

    //attach shader
    glAttachShader(this->id, shaderId);

    return shaderId;
}

// void ShaderProgram::addShader(std::string path, GLenum shaderType){
//     this->shaders.push_back(initShader(path, shaderType));
// }

// void ShaderProgram::attachShaders(){
    // for (auto shaderId = this->shaders.begin(); shaderId != this->shaders.end(); ++shaderId){
    //     glAttachShader(this->id, *shaderId);
    // }
// }


// void ShaderProgram::deleteShaders(){
//     for (auto shaderId = this->shaders.begin(); shaderId != this->shaders.end(); ++shaderId){
//         glDeleteShader(*shaderId);
//     }
// }

void ShaderProgram::use(){
    glUseProgram(this->id);
}