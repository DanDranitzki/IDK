#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <headers/window.h>
#include <headers/rawModel.h>
#include <headers/shaderProgram.h>
#include <headers/renderer.h>
#include <headers/texture.h>
#include <headers/texturedModel.h>
#include <headers/entity.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

int main(){

	Window window(SCR_WIDTH, SCR_HEIGHT, "idk");

	window.createWindow();

	float vertices[] = {
     	0.5f,  0.5f, 0.0f,  // top right
    	0.5f, -0.5f, 0.0f,  // bottom right
    	-0.5f, -0.5f, 0.0f,  // bottom left
    	-0.5f,  0.5f, 0.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
    	0, 1, 3,   // first triangle
    	1, 2, 3    // second triangle
	};

	float textureCoords[] = {
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f
	};

	RawModel model(vertices, sizeof(vertices), textureCoords, sizeof(textureCoords), indices, sizeof(indices));

	Texture texture("res/textures/test.png");

	TexturedModel texturedModel(&model, &texture);
	Entity entity(&texturedModel, &glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));

	Shader shader("res/shaders/vertexShader.glsl", "res/shaders/fragmentShader.glsl");

	Renderer renderer;
	renderer.init(shader);

	while(!glfwWindowShouldClose(window.getWindow())){
		window.processInput(window.getWindow());

		//rendering here
		renderer.prepareRender();
		renderer.render(entity, shader);

		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}
	shader.cleanUp();
	glfwTerminate();

	return 0;
}