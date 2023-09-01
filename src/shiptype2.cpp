#include <iostream>
#include <vector>
#include "shiptype2.hpp"

void shiptype2::toggle_ship()
{
    its_space.change_ship_con(row - 1, col);
    its_space.change_ship_con(row - 1, col + 4);

    its_space.change_ship_con(row - 2, col);
    its_space.change_ship_con(row - 2, col + 1);
    its_space.change_ship_con(row - 2, col + 2);
    its_space.change_ship_con(row - 2, col + 3);
    its_space.change_ship_con(row - 2, col + 4);

    its_space.change_ship_con(row - 3, col);
    its_space.change_ship_con(row - 3, col + 2);
    its_space.change_ship_con(row - 3, col + 4);

    its_space.change_ship_con(row - 4, col + 2);
}

