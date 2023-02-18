#ifndef shaderProgram_H
#define shaderProgram_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader{
    private:
        const char *vertexShaderSource;
        const char *fragmentShaderSource;
        unsigned int shaderProgram;
        unsigned int vertexShader;
        unsigned int fragmentShader;
        void loadShader(const std::string vertexPath, const std::string fragmentPath);
        void setBool(const std::string &name, bool value);
        void setFloat(const std::string &name, float value);

    public:
        Shader(const std::string vertexPath, const std::string fragmentPath);
        void useShader();
        void cleanUp();
        void useUniforms();
        void setInt(const std::string &name, int value);
};

#endif