#include "class_mouse.h"
#include "class_body.h"

Coord Mouse::clickPos;
Coord Mouse::mousPos;
bool Mouse::clicked;
bool Mouse::release;

Circle Mouse::hovCircle( Coord( 0, 0 ), 10 );
double Mouse::mass = 500000.0;

bool Mouse::keys[256];

Mouse::Mouse()
{



}

void Mouse::keyFunc( GLFWwindow *wind, int key, int scancode, int action, int mods )
{

    if( action == GLFW_PRESS )
    {

        keys[key] = true;

    }else if( action == GLFW_RELEASE )
    {

        keys[key] = false;

    }

}

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

void Mouse::draw()
{

    glTranslatef( 0.0f, 0.0f, -1.0f );

    double color = mass/1000000.0;
    
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
    
    glEnableClientState( GL_COLOR_ARRAY );
    glEnableClientState( GL_VERTEX_ARRAY );
    
    hovCircle.draw( color, 0.0, 1-color, 0.4 );
    
    glDisableClientState( GL_COLOR_ARRAY );
    glDisableClientState( GL_VERTEX_ARRAY );
    
}

void Mouse::input()
{

    if( keys[GLFW_KEY_Q] )
    {
        
        if( hovCircle.r < 200 )
        {   
            hovCircle.r++;
            std::cout << hovCircle.r << std::endl;
        }

    }else if( keys[GLFW_KEY_A] )
    {

        if( hovCircle.r > 1 )
        {
            hovCircle.r--;
        }

    }

    int changespeed = 5000;
    if( keys[GLFW_KEY_W] )
    {

        if( mass < 1000000-changespeed )
        {

            mass+=changespeed;

        }

    }else if( keys[GLFW_KEY_S] )
    {

        if( mass > changespeed )
        {

            mass-=changespeed;

        }

    }

}

void Mouse::run()
{

    int w,h;
    glfwGetWindowSize( glfwGetCurrentContext(), &w, &h );

    int xshift = -(w/2.0);
    int yshift = -(h/2.0);

    hovCircle.pos = Coord( mousPos.x+xshift, mousPos.y+yshift );

    if( release )
    {
        
        Vector init( 0, 0 );
        double mag = init.getDist( clickPos, mousPos )/1000.0;
        std::cout << mag << std::endl;

        double ang = init.getAngle( mousPos, clickPos );
        init = Vector( ang, mag );

        Body *newBody = new Body( Coord( mousPos.x + xshift, mousPos.y + yshift ), hovCircle.r, mass, init );
        if( newBody == nullptr )
        {

            std::cout << "uh oh" << std::endl;

        }

    }

    release = false;

}
