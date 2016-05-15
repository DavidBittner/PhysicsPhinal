#include "class_engine.h"

Init Engine::stInit;
Poll Engine::stPoll;
Render Engine::stRender;
Process Engine::stProcess;
Terminate Engine::stTerminate;

State *Engine::curState;

Engine &Machine()
{

    static Engine *Musheen = new Engine();
    return *Musheen;

}

State *Engine::getState()
{

    return curState;

}

Engine::Engine()
{

    curState = &stInit;

}

void Engine::fire()
{

    curState = curState->exec();

}

void Engine::glReshape( GLFWwindow *wind, int width, int height )
{

    glfwMakeContextCurrent( wind );

    glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -width/2.0, width/2, -height/2, height/2, 1.0f, 10.0f );
    glMatrixMode( GL_MODELVIEW );

}

void Engine::runInits()
{

    static Body testPlanet( Coord( 0, 0 ), 10, 100000 );
    static Body testPlanet2( Coord( 100, 100 ), 10, 10 );

}
