#ifndef RENDERERS_H
#define RENDERERS_H


class GLRenderer{ 
public:
    GLRenderer(){}
    virtual ~GLRenderer(){}
};

class BlockRenderer : public GLRenderer {
public:
    BlockRenderer();
};

extern BlockRenderer BLOCK_RENDERER;
#endif