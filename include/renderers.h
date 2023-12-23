#ifndef RENDERERS_H
#define RENDERERS_H

#include <glad/glad.h>

// struct Renderers{
//     static BlockRenderer 
// };

class GLRenderer{ 
public:
    GLRenderer(){}
    virtual void initBuffers() = 0;
    // virtual void render();
    virtual ~GLRenderer(){}
};

class BlockRenderer : public GLRenderer {
private:
    static inline float BLOCK_VERTICES[] = {
        0.5f, 0.5f, 0.5f,   //right up forward 0
        0.5f, 0.5f, -0.5f,  //right up back 1
        0.5f, -0.5f, 0.5f,  //right down forward 2
        0.5f, -0.5f, -0.5f, //right down back 3
        -0.5f, 0.5f, 0.5f,  //left up forward 4
        -0.5f, 0.5f, -0.5f, //left up back 5
        -0.5f, -0.5f, 0.5f, //left down forward 6
        -0.5f, -0.5f, -0.5f //left down back 7
    };
    static inline int BLOCK_INDICES[] = {
        /* Faces */
        //front
        0, 2, 4,
        6, 2, 4,
        //back
        1, 3, 5,
        7, 3, 5,
        //left
        4, 5, 6,
        7, 5, 6,
        //right
        0, 1, 2,
        3, 1, 2,
        //up
        0, 1, 4,
        5, 1, 4,
        //down
        2, 3, 6,
        7, 3, 6
    };
public:
    unsigned int VBO, EBO, VAO;

    BlockRenderer();
    void initBuffers();
    // void render();
};

extern BlockRenderer BLOCK_RENDERER;
#endif