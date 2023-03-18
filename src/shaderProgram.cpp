#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <headers/shaderProgram.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

void Shader::loadShader(const std::string vertexPath, const std::string fragmentPath){
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}catch(std::ifstream::failure e){
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	int success;
	char infoLog[512];

	this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(this->vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(this->vertexShader);

	glGetShaderiv(this->vertexShader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(this->vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(this->fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(this->fragmentShader);

	glGetShaderiv(this->fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(this->fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	this->shaderProgram = glCreateProgram();
	glAttachShader(this->shaderProgram, this->vertexShader);
	glAttachShader(this->shaderProgram, this->fragmentShader);
	glLinkProgram(this->shaderProgram);

	glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
	if(!success){
		glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}

Shader::Shader(const std::string vertexPath, const std::string fragmentPath){
    loadShader(vertexPath, fragmentPath);
}

void Shader::useShader(){
    glUseProgram(this->shaderProgram);
}

void Shader::cleanUp(){
	glDetachShader(this->shaderProgram, this->vertexShader);
	glDetachShader(this->shaderProgram, this->fragmentShader);
	glDeleteShader(this->vertexShader);
	glDeleteShader(this->fragmentShader);
	glDeleteProgram(this->shaderProgram);
}

void Shader::setBool(const std::string &name, bool value){         
    glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), (int)value); 
}

void Shader::setInt(const std::string &name, int value){ 
    glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), value); 
}

void Shader::setFloat(const std::string &name, float value){ 
    glUniform1f(glGetUniformLocation(this->shaderProgram, name.c_str()), value); 
}

void Shader::setMat4(const std::string &name, glm::mat4 value){
	glUniformMatrix4fv(glGetUniformLocation(this->shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void useUniforms(){}