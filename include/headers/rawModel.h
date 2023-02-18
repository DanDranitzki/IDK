#ifndef rawModel_H
#define rawModel_H

class RawModel{
    private:
        unsigned int VAO;
        int vertexCount;
        unsigned int createVAO();
        void unbindVAO();
        void createArrayBuffer(int attributeNum, int dataSize, float data[], int dataArraySize);
        void createIndicesBuffer(unsigned int indices[], int indicesArraySize);

    public:
        RawModel(float vertices[], int verticesSize, float textureCoords[], int textureCoordSize, unsigned int indices[], int indicesSize);
        unsigned int getVAO();
        int getVertexCount();
};

#endif