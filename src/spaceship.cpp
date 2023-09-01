#include "spaceship.hpp"

void spaceship::move_r()
{
    if (col >= (its_space.width_s() - width())) return;

    toggle_ship();
    col++;
    toggle_ship();
}

void spaceship::move_l()
{
    if (col <= 0) return;

    toggle_ship();
    col--;
    toggle_ship();
}

void spaceship::move_u()
{
    if (row <= height()) return;

    toggle_ship();
    row--;
    toggle_ship();
}

void spaceship::move_d()
{
    if (row >= its_space.height_s()) return;

    toggle_ship();
    row++;
    toggle_ship();
}

