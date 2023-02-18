#ifndef renderer_H
#define renderer_H
#include <headers/rawModel.h>
#include <headers/shaderProgram.h>
#include <headers/texture.h>

class Renderer{
    public:
        void init(Shader shader);
        void prepareRender();
        void render(RawModel model, Texture texture, Shader shader);
};

#endif