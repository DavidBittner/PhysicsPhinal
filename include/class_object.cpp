#include "class_object.h"
#include "class_body.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const double G = 0.0000000000667408;

Object::Object()
{



}

std::vector<Object*> &Object::matter()
{

    static std::vector<Object*> *matterVec = new std::vector<Object*>();
    return *matterVec;

}

void Object::draw()
{

    glEnableClientState( GL_VERTEX_ARRAY );

    for( Object *i : matter() )
    {

        i->draw();

    }

    glDisableClientState( GL_VERTEX_ARRAY );

}

void Object::attract( Vector atr )
{

    atr.mag = atr.mag;
    //Do nothing.

}

void Object::move()
{

    for( int i = 0; i < TIME_STEP; i++ )
    {
        
        for( unsigned i = 0; i < matter().size(); i++ )
        {

            for( unsigned j = 0; j < matter().size(); j++ )
            {

                if( i == j )
                {

                    continue;

                }

                Vector finalVec( 0, 0 );
                double ang = finalVec.getAngle( matter().at(i)->getPos(), matter().at(j)->getPos() );
                double dist = finalVec.getDist( matter().at(i)->getPos(), matter().at(j)->getPos() );
                double mass = matter().at(j)->getMass();

                finalVec.mag = ((G*mass)/(pow( dist/1000.0, 2 )));
                finalVec.ang = ang;

                matter().at(i)->attract( finalVec );

            }

        }

        for( Object *i : matter() )
        {

            i->move();

        }

    }

}

double Object::xVel()
{

    std::cout << "What? Super classes don't have velocity." << std::endl;
    return 0.0;

}

double Object::yVel()
{

    std::cout << "What? Super classes don't have velocity." << std::endl;
    return 0.0;

}

Vector Object::getVector()
{

    return Vector( 0, 0 );

}

Coord Object::getPos()
{

    return Coord( 0, 0 );

}

double Object::getMass()
{

    return 0.0;

}
