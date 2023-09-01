#pragma once

#include <vector>
#include "field.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "spaceship.hpp"

class shiptype1 : public spaceship
{
public:
    shiptype1(space &its_space)
        : spaceship(its_space, its_space.width_s() / 2, its_space.height_s() - 4)
    {
    }

    virtual int width() const { return 5; };
    virtual int height() const { return 4; };
    void toggle_ship() override;
};

