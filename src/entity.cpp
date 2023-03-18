#include <headers/entity.h>
#include <headers/texturedModel.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

Entity::Entity(TexturedModel *model, glm::vec4 *position){
    this->model = model;
    this->pos = position;
}

TexturedModel Entity::getTexturedModel(){
    return *this->model;
}

glm::vec4 Entity::getPosition(){
    return *this->pos;
}