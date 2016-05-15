#pragma once

#include "class_object.h"

class Body : public Object
{

    public:
        Body( Coord pos, double radius, double mass );

        void move();
        void draw();

        double xVel();
        double yVel();

        void attract( Vector atr );

        Vector getVector();
        Coord getPos();
        double getMass();

};
