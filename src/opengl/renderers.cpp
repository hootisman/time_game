#include "../../include/renderers.h"

BlockRenderer BLOCK_RENDERER;

// const float BLOCK_VERTICES[] = {
//     0.5f, 0.5f, 0.5f,   //right up forward 0
//     0.5f, 0.5f, -0.5f,  //right up back 1
//     0.5f, -0.5f, 0.5f,  //right down forward 2
//     0.5f, -0.5f, -0.5f, //right down back 3
//     -0.5f, 0.5f, 0.5f,  //left up forward 4
//     -0.5f, 0.5f, -0.5f, //left up back 5
//     -0.5f, -0.5f, 0.5f, //left down forward 6
//     -0.5f, -0.5f, -0.5f //left down back 7
// };

// const int BLOCK_INDICES[] = {
//     /* Faces */
//     //front
//     0, 2, 4,
//     6, 2, 4,
//     //back
//     1, 3, 5,
//     7, 3, 5,
//     //left
//     4, 5, 6,
//     7, 5, 6,
//     //right
//     0, 1, 2,
//     3, 1, 2,
//     //up
//     0, 1, 4,
//     5, 1, 4,
//     //down
//     2, 3, 6,
//     7, 3, 6
// };


void BlockRenderer::initBuffers(){
    glGenVertexArrays(1, &(this->VAO));
    glBindVertexArray(this->VAO);
    glGenBuffers(1, &(this->VBO));
    glGenBuffers(1, &(this->EBO));

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->BLOCK_VERTICES), this->BLOCK_VERTICES, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->BLOCK_INDICES), this->BLOCK_INDICES, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);


    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
BlockRenderer::BlockRenderer() {
    this->initBuffers();
}