#include "class_mouse.h"
#include "class_body.h"

Coord Mouse::clickPos;
Coord Mouse::mousPos;
bool Mouse::clicked;
bool Mouse::release;

void Mouse::mousePos( GLFWwindow *wind, double x, double y )
{

    int w,h;
    glfwGetWindowSize( glfwGetCurrentContext(), &w, &h );

    mousPos.x = x;
    mousPos.y = h-y;

}

void Mouse::mouseClick( GLFWwindow *wind, int button, int action, int mods )
{

    if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS )
    {

        if( !clicked )
        {

            clickPos = Coord( mousPos.x, mousPos.y );

        }
        clicked = true;
        
    }else if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE )
    {

        clicked = false;
        release = true;

    }

}

void Mouse::run()
{

    int w,h;
    glfwGetWindowSize( glfwGetCurrentContext(), &w, &h );

    int xshift = -(w/2.0);
    int yshift = -(h/2.0);


    if( clicked )
    {
        glBegin( GL_LINES );
            glVertex2f( mousPos.x+xshift, mousPos.y+yshift );
            glVertex2f( clickPos.x+xshift, clickPos.y+yshift );
        glEnd();

    }

    if( release )
    {
        
        Vector init( 0, 0 );
        double mag = init.getDist( clickPos, mousPos )/1000.0;
        std::cout << mag << std::endl;

        double ang = init.getAngle( mousPos, clickPos );
        init = Vector( ang, mag );

        Body *newBody = new Body( Coord( mousPos.x + xshift, mousPos.y + yshift ), 10, 1000000, init );

    }

    release = false;

}
