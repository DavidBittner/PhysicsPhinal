#pragma once

struct Coord
{

    Coord();
    Coord( int x, int y );
    
    template<class T>
    Coord( T x, T y )
    {

        this->x = x;
        this->y = y;

    }

    float x, y;

    bool operator== ( Coord b )
    {

        return (this->x==b.x)&&(this->y==b.y);

    }

};
