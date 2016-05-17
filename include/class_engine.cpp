#include <thread>
#include <chrono>

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

    Body *planet =  new Body( Coord( 0, 0 ), 10, 10000000 );
    Body *planet2 = new Body( Coord( 200, 0 ), 10, 0.05, Vector( 5*PI/4, 0.005 ) );

    if( planet == nullptr || planet2 == nullptr )
    {



    }

}

void Engine::start()
{

    int st = glfwGetTime();

    if( st == -1 )
    {
        
        st = 0;

    }

}

void Engine::cap()
{

    int en = glfwGetTime();

    if( en-st < 1000.0/FRAMES_PER_SECOND )
    {

        std::this_thread::sleep_for( std::chrono::milliseconds( (int)((1000.0/FRAMES_PER_SECOND)-(en-st)) ) );

    }

}
