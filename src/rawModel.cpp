#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <headers/rawModel.h>

unsigned int RawModel::createVAO(){
    unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
    return VAO;
}

void RawModel::unbindVAO(){
    glBindVertexArray(0);
}

void RawModel::createArrayBuffer(int attributeNum, int dataSize, float data[], int dataArraySize){
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, dataArraySize, data, GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNum, dataSize, GL_FLOAT, GL_FALSE, dataSize * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void RawModel::createIndicesBuffer(unsigned int indices[], int indicesArraySize){
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesArraySize, indices, GL_STATIC_DRAW);
    this->vertexCount = indicesArraySize;
}

RawModel::RawModel(float vertices[], int verticesSize, float textureCoords[], int textureCoordSize, unsigned int indices[], int indicesSize){
    this->VAO = createVAO();
    createArrayBuffer(0, 3, vertices, verticesSize);
    createArrayBuffer(1, 2, textureCoords, textureCoordSize);
    createIndicesBuffer(indices, indicesSize);
    unbindVAO();
}

unsigned int RawModel::getVAO(){
    return this->VAO;
}

int RawModel::getVertexCount(){
    return this->vertexCount;
}