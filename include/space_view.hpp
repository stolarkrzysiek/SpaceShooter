#pragma once 

#include <vector>
#include <string> 
#include <ncurses.h>
#include "space.hpp"

class space_view
{
    public:
        space_view(space &game,int height, int width);
        void initialize();
        void addBoarder();
        void addAt(int y, int x, chtype ch);
        void clear();
        void refresh();
        void show_board();
        







    private:
        WINDOW *board_win;
        space &gamev;



};
