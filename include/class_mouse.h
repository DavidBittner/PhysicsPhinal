#pragma once

#include <GLFW/glfw3.h>

#include "struct_coord.h"
#include "struct_circle.h"

class Mouse
{

    public:
        Mouse();

        void run();
        void draw();
        void input();
    
        static void mousePos( GLFWwindow *wind, double x, double y );
        static void mouseClick( GLFWwindow *wind, int button, int action, int mods );
        
        static void keyFunc( GLFWwindow *wind, int key, int scancode, int action, int mods );
        
    private:
        static Coord clickPos;
        static Coord mousPos;
        static bool clicked;
        static bool release;

        static Circle hovCircle;
        static double mass;

        static bool keys[256];

};
