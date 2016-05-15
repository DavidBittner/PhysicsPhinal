#pragma once

#include <cmath>
#include <iostream>

#include "struct_coord.h"

const double PI = 3.14159;

struct Vector
{

    Vector();
    Vector( double ang, double mag );

    double mag, ang;

    double getAngle( Coord a, Coord b );
    double getDist( Coord a, Coord b );

    Vector operator+( Vector b )
    {

        double x = (cos(b.ang)*b.mag)+(cos(this->ang)*this->mag);
        double y = (sin(b.ang)*b.mag)+(sin(this->ang)*this->mag);

        double newmag = sqrt( pow( x, 2 ) + pow( y, 2 ) );

        double newang = getAngle( Coord( 0, 0 ), Coord( x, y ) );

        return Vector( newang, newmag );

    }
    
    bool operator==( Vector b )
    { 

        return (b.mag == this->mag)&&(b.ang == this->ang); 
    
    }

    

};
