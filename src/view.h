#ifndef VIEW_H
#define VIEW_H

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class View{
 public:
    View(int height, int width, const::string& title);
    virtual ~View();

 private:
    View(const View& other){};
    GLFWwindow* window;
}

#endif
