#pragma once

#include <vector>

#include "struct_vector.h"
#include "struct_circle.h"

class Object
{

    public:
        Object();

        virtual void draw();
        virtual void move();

        virtual double xVel();
        virtual double yVel();
        virtual double getMass();

        virtual void attract( Vector atr );

        virtual Vector getVector();
        virtual Coord getPos();

        static std::vector<Object*> &matter();

    protected:
        Vector movDir;
        Circle colPos;

        //In kilograms
        float mass;

        const int TIME_STEP = 100;

};
