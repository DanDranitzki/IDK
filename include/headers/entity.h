#ifndef renderer_H
#define renderer_H
#include <headers/texturedModel.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Entity{
    private:
        TexturedModel *model;
        glm::vec4 *pos;

    public:
        Entity(TexturedModel *model, glm::vec4 *position);
        TexturedModel getTexturedModel();
        glm::vec4 getPosition();
};

#endif