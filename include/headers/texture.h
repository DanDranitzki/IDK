#ifndef texture_H
#define texture_H
#include <string>

class Texture{
    private:
        unsigned int textureID;
    public:
        Texture(const char* textureFile);
        unsigned int getTextureID();
};

#endif