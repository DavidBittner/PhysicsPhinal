#include "class_states.h"
#include "class_state.h"
#include "class_engine.h"
#include "class_body.h"
#include "class_mouse.h"

#include <iostream>

#include <GLFW/glfw3.h>

State *Init::exec()
{

    glewInit();
    glfwInit();

    glfwWindowHint( GLFW_SAMPLES, 4 );
    GLFWwindow *wind = glfwCreateWindow( 800, 600, "Physics Phinal", nullptr, nullptr );
    glfwMakeContextCurrent( wind );

    glfwSwapInterval( 1 );

    glfwSetWindowSizeCallback( wind, Engine::glReshape );

    glfwSetMouseButtonCallback( wind, Mouse::mouseClick );
    glfwSetCursorPosCallback( wind, Mouse::mousePos );
    
    glfwSetKeyCallback( wind, Mouse::keyFunc );

    Machine().glReshape( wind, 800, 600 );

    Body *planet = new Body( Coord( 0, 0 ), 10, 10000000 ); 

    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    return &Engine::stPoll;

}

State *Poll::exec()
{

    Machine().start();

    glfwPollEvents();
    Mouse launcher;
    launcher.input();

    if( !glfwWindowShouldClose( glfwGetCurrentContext() ) )
    {
        return &Engine::stProcess;
    }
    else
    {
        return &Engine::stTerminate;
    }

}

State *Process::exec()
{

    Object objController;
    Mouse launcher;
    
    launcher.run();
    objController.move();

    return &Engine::stRender;

}

State *Render::exec()
{

    glClear( GL_COLOR_BUFFER_BIT );
    glLoadIdentity();

    Mouse launcher;
    Object objController;

    glTranslatef( 0.0f, 0.0f, -1.0f );

    launcher.draw();
    objController.draw();

    glfwSwapBuffers( glfwGetCurrentContext() );

    Machine().cap();

    return &Engine::stPoll;

}

State *Terminate::exec()
{

    glfwTerminate();

    return nullptr;
    
}
