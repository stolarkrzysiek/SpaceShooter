#pragma once 
#include <ncurses.h>


class menu
{
    public:
        menu(int height, int width);
        void initialize();
        void addBoarder();
        void clear();
        void refresh();
        void show_menu();
        void end(int score);
    private:
        WINDOW *board_win;
        int height, width;
};
