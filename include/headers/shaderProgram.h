#ifndef shaderProgram_H
#define shaderProgram_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader{
    private:
        const char *vertexShaderSource;
        const char *fragmentShaderSource;
        unsigned int shaderProgram;
        unsigned int vertexShader;
        unsigned int fragmentShader;
        void loadShader(const std::string vertexPath, const std::string fragmentPath);
    
    public:
        Shader(const std::string vertexPath, const std::string fragmentPath);
        void useShader();
        void cleanUp();
        void useUniforms();
        void setInt(const std::string &name, int value);
        void setBool(const std::string &name, bool value);
        void setFloat(const std::string &name, float value);
        void setMat4(const std::string &name, glm::mat4 value);
        
};

#endif