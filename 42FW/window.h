#ifndef WINDOW_H
#define WINDOW_H

#include "reference.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Window
{
    public:
        Window(int width, int height, const char* title, bool resizable);
        virtual ~Window();

        bool IsOpen();
        void Destroy();
        void Update();

        bool GetKey(int key);
        bool GetMouseButton(int button, float camX, float camY);

        int wWidth = 800;
        int wHeight = 600;

        double mouseX, mouseY;
        bool lmb, rmb;

    protected:

    private:
        GLFWwindow* window;
};

#endif // WINDOW_H
