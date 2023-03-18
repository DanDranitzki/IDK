#include <headers/texturedModel.h>
#include <headers/rawModel.h>
#include <headers/texture.h>

TexturedModel::TexturedModel(RawModel *model, Texture *texture){
    this->model = model;
    this->texture = texture;
}

RawModel TexturedModel::getModel(){
    return *this->model;
}

Texture TexturedModel::getTexture(){
    return *this->texture;
}