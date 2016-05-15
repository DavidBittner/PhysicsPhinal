#pragma once

#include "class_state.h"

class Init : public State
{
    public:
        State *exec();

};

class Poll : public State
{
    public:
        State *exec();

};

class Process : public State
{
    public:
        State *exec();

};

class Render : public State
{
    public:
        State *exec();

};

class Terminate : public State
{
    public:
        State *exec();

};
