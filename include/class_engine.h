#include <GL/glew.h>
#pragma once

#include <GLFW/glfw3.h>

#include "class_states.h"
#include "class_body.h"

class Engine
{

    friend Init;
    friend Poll;
    friend Process;
    friend Render;
    friend Terminate;

    public:
        Engine();

        void fire();
        State *getState();

        void runInits();

    protected:
        static Init stInit;
        static Poll stPoll;
        static Process stProcess;
        static Render stRender;
        static Terminate stTerminate;

        static State *curState;

        static void glReshape( GLFWwindow *wind, int width, int height );

        void start();
        void cap();

    private:
        int st;
        int en;
        const int FRAMES_PER_SECOND = 60;

};

Engine &Machine();
