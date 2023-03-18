#ifndef renderer_H
#define renderer_H
#include <headers/shaderProgram.h>
#include <headers/entity.h>

class Renderer{
    public:
        void init(Shader shader);
        void prepareRender();
        void render(Entity entity, Shader shader);
};

#endif