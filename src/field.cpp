#include <iostream>
#include "field.hpp"
using namespace std;

field::field()
{
    this->hasship = false;
    this->hasrock = false;
}

char field::ship_con()
{
    if (this->hasship == true)
    {
        return 's';
    }
    else
    {
        return ' ';
    }
}

char field::rock_con()
{
    if (this->hasrock == true)
    {
        return 'r';
    }
    else
    {
        return ' ';
    }
}

void field::change_ship_con()
{
    hasship = !hasship;
}

void field::change_rock_con()
{
    if (this->hasrock == true)
    {
        this->hasrock = false;
    }
    else
    {
        this->hasrock = true;
    }
}

