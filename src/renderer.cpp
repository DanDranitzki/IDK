#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <headers/rawModel.h>
#include <headers/shaderProgram.h>
#include <headers/renderer.h>
#include <headers/texture.h>
#include <headers/texturedModel.h>
#include <headers/entity.h>

void Renderer::init(Shader shader){
    shader.useShader();
    shader.setInt("ourTexture", 0);
}

void Renderer::prepareRender(){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(Entity entity, Shader shader){
    TexturedModel texturedModel = entity.getTexturedModel();
    RawModel model = texturedModel.getModel();
    Texture texture = texturedModel.getTexture();
    glBindVertexArray(model.getVAO());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    shader.useShader();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture.getTextureID());
    glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}