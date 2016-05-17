#include "class_states.h"
#include "class_state.h"
#include "class_engine.h"
#include "class_body.h"

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

    glfwSetWindowSizeCallback( wind, Machine().glReshape );
    Machine().glReshape( wind, 800, 600 );

    Machine().runInits();

    return &Engine::stPoll;

}

State *Poll::exec()
{

    Machine().start();

    glfwPollEvents();

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
    objController.move();

    return &Engine::stRender;

}

State *Render::exec()
{

    glClear( GL_COLOR_BUFFER_BIT );
    glLoadIdentity();

    glTranslatef( 0.0f, 0.0f, -1.0f );

    Object objController;
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
