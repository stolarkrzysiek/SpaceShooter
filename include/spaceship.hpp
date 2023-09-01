#pragma once
#include "space.hpp"

struct spaceship
{
    spaceship(space &its_space, int col, int row)
        : its_space(its_space), col{col}, row{row}
    {
    }
    virtual ~spaceship() {}

    virtual void toggle_ship() = 0;
    virtual int width() const = 0;
    virtual int height() const = 0;
    
    void move_r();
    void move_l();
    void move_u();
    void move_d();

protected:
    space &its_space;
    int col;
    int row;
};

