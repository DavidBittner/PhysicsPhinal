#pragma once

#include "struct_coord.h"

struct Circle
{

    Circle();
    Circle( double x, double y, double r );
    Circle( Coord pos, double r );

    bool checkCollision( Circle a );
    void draw( double rc, double gc, double bc, double ac );

    double r;
    Coord pos;

};
