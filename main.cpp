#include "include/class_engine.h"
#include "include/struct_vector.h"

#include <iostream>

int main()
{

    Machine();

    while( Machine().getState() != nullptr )
    {

        Machine().fire();

    }

}
