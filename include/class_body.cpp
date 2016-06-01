#include "class_body.h"

Body::Body( Coord pos, double radius, double mass )
{

    this->mass = mass;
    this->colPos.r = radius;

    this->colPos.pos = pos;

    movDir = Vector( 0.0f, 0.0f );

    matter().push_back( this );

}

Body::Body( Coord pos, double radius, double mass, Vector init )
{

    this->mass = mass;
    this->colPos.r = radius;

    this->colPos.pos = pos;

    movDir = init;

    matter().push_back( this );

}

void Body::move()
{

    colPos.pos.x += cos( movDir.ang )*movDir.mag; 
    colPos.pos.y += sin( movDir.ang )*movDir.mag;

}

void Body::draw()
{

    double color = mass/1000000.0;
    colPos.draw( color, 0.0, 1-color, 1.0 );

}

double Body::xVel()
{

    return cos(movDir.ang)*movDir.mag;

}

double Body::yVel()
{

    return sin(movDir.ang)*movDir.mag;

}

double Body::getMass()
{

    return mass;

}

Vector Body::getVector()
{

    return movDir;

}

void Body::attract( Vector atr )
{

    movDir = movDir + atr;

}

Coord Body::getPos()
{

    return colPos.pos;

}
