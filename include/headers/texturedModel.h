#ifndef texturedModel_H
#define texturedModel_H
#include <headers/rawModel.h>
#include <headers/texture.h>

class TexturedModel{
    private:
        RawModel *model;
        Texture *texture;

    public:
        TexturedModel(RawModel *model, Texture *texture);
        RawModel getModel();
        Texture getTexture();
};
#endif