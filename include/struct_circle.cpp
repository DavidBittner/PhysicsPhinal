#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "struct_circle.h"

const double PI = 3.14159;

Circle::Circle()
{

    pos.x = 0;
    pos.y = 0;
    r = 0;

}

Circle::Circle( double x, double y, double r )
{

    pos.x = x;
    pos.y = y;

    this->r = r;

}

Circle::Circle( Coord pos, double r )
{

    this->pos = pos;
    this->r = r;

}

bool Circle::checkCollision( Circle a )
{

    double dx = a.pos.x - pos.x;
    double dy = a.pos.y - pos.y;
    double dist = hypot( dx, dy );

    if( dist <= a.r + r )
    {

        return true;

    }else
    {

        return false;

    }

}

void Circle::draw( double rc, double gc, double bc, double ac )
{

    int acr = 32;
    int index = 2;

    int vertAmount = acr*2+4;

    //Add four to account for center coord because triangle fans and the last two coords
    double verts[vertAmount];
    double colrs[vertAmount*4];

    verts[0] = pos.x;
    verts[1] = pos.y;

    for( double i = 0; i < 2*PI; i+=((2*PI)*(1.0/acr)) )
    {

        verts[index] = cos( i )*r + pos.x;
        verts[index+1] = sin( i )*r + pos.y;

        index+=2;

    }

    for( int i = 0; i < vertAmount*4; i+=4 )
    {

        colrs[i] = rc;
        colrs[i+1] = gc;
        colrs[i+2] = bc;
        colrs[i+3] = ac;

    }

    verts[vertAmount-2] = cos( 0 )*r + pos.x;
    verts[vertAmount-1] = sin( 0 )*r + pos.y;

    glVertexPointer( 2, GL_DOUBLE, 0, verts );
    glColorPointer( 4, GL_DOUBLE, 0, colrs );
    glDrawArrays( GL_TRIANGLE_FAN, 0, vertAmount/2 );

}
