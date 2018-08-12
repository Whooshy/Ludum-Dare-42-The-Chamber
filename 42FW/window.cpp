#include "window.h"

int key_[8];
int ww, wh;

double cursorX, cursorY;
bool LMB, RMB;

void ResizeCallback(GLFWwindow* window, int width, int height);
void MouseCallback(GLFWwindow* window, double xPos, double yPos);
void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

Window::Window(int width, int height, const char* title, bool resizable)
{
    ww = width;
    wh = height;

    glfwInit();

    glfwWindowHint(GLFW_RESIZABLE, resizable);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    window = glfwCreateWindow(width, height, title, NULL, NULL);

    glfwSetFramebufferSizeCallback(window, ResizeCallback);
    glfwSetCursorPosCallback(window, MouseCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);

    glfwMakeContextCurrent(window);
    glewInit();
}

bool Window::IsOpen()
{
    if(glfwWindowShouldClose(window) == GLFW_TRUE)
        return false;
    else return true;
}

bool Window::GetKey(int key)
{
    if(glfwGetKey(window, key) == GLFW_PRESS)
        return true;
    return false;
}

void MouseCallback(GLFWwindow* window, double xPos, double yPos)
{
    cursorX = xPos;
    cursorY = yPos;
}

void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
        LMB = true;
    if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_RELEASE)
        LMB = false;

    if(button == GLFW_MOUSE_BUTTON_2 && action == GLFW_PRESS)
        RMB = true;
    if(button == GLFW_MOUSE_BUTTON_2 && action == GLFW_RELEASE)
        RMB = false;
}

void Window::Destroy()
{
    glfwDestroyWindow(window);
}

void Window::Update()
{
    wWidth = ww;
    wHeight = wh;

    mouseX = cursorX;
    mouseY = cursorY;

    lmb = LMB;
    rmb = RMB;

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void ResizeCallback(GLFWwindow* window, int width, int height)
{
    ww = width;
    wh = height;
    glViewport(0, 0, width, height);
}

Window::~Window()
{
    //dtor
}
