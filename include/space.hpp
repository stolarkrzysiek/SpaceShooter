#pragma once

#include <vector>
#include "field.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class space
{
private:
    std::vector<field> Board;
    int width, height;

public:
    space(int width, int height);

    field &at(int row, int col);

    void show_space();
    void change_ship_con(int row, int col);
    void change_rock_con(int row, int col);
    void rock_gen();
    void next_con_rock();
    virtual ~space(){};
    int width_s();
    int height_s();

    void move_ship();
    bool game_status();
    char get_field_info(int row, int col);
};

