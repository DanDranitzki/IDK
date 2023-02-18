#ifndef window_H
#define window_H
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window{

    private:
        int width;
        int height;
        std::string title;
        GLFWwindow* window;

        void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    public:
        Window(int width, int heigh, std::string title);
        int createWindow();
        void processInput(GLFWwindow* window);
        GLFWwindow* getWindow();

};

#endif