#pragma once

#include <GLFW/glfw3.h>

#include "struct_coord.h"

class Mouse
{

    public:
        void run();
    
        static void mousePos( GLFWwindow *wind, double x, double y );
        static void mouseClick( GLFWwindow *wind, int button, int action, int mods );
        
    private:
        static Coord clickPos;
        static Coord mousPos;
        static bool clicked;
        static bool release;

};
