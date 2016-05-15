#include "struct_vector.h"

Vector::Vector()
{

    mag = 0.0;
    ang = 0.0;

}

Vector::Vector( double ang, double mag )
{

    this->ang = ang;
    this->mag = mag;

}

double Vector::getAngle( Coord a, Coord b )
{

    double dx = b.x - a.x;
    double dy = b.y - a.y;

    if( dx == 0 )
    {

        if( dy > 0 )
        {

            return 90.0;

        }else
        {

            return 270.0;

        }

    }
    
    if( dy == 0 )
    {

        if( dx > 0 )
        {

            return 0.0;

        }else
        {

            return 180.0;

        }

    }

    if( dx > 0 && dy > 0 )
    {

        return atan(dy/dx);

    }else if( dx < 0 && dy > 0 )
    {

        return atan(dy/dx)+PI;

    }else if( dx < 0 && dy < 0 )
    {

        return atan(dy/dx)+PI;

    }else if( dx > 0 && dy < 0 )
    {

        return atan(dy/dx)+(2*PI);

    }

    return atan( dy/dx );

}

double Vector::getDist( Coord a, Coord b )
{

    return sqrt( pow( b.x-a.x, 2 ) + pow( b.y - a.y, 2 ) );

}
