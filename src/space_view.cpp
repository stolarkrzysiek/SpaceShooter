#include "space.hpp"
#include "space_view.hpp"
#include <ncurses.h>
#include <iostream>
using namespace std;

space_view::space_view(space &game, int height, int width) : gamev(game)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    board_win = newwin(height+2, width+2, (yMax / 2) - (height / 2), (xMax / 2) - (width / 2));
}

void space_view::refresh()
{
    wrefresh(board_win);
}

void space_view::clear()
{
    wclear(board_win);
    addBoarder();
}

void space_view::initialize()
{
    clear();
    refresh();
}

void space_view::addBoarder()
{
    box(board_win, 0, 0);
}

void space_view::addAt(int y, int x, chtype ch)
{
    mvwaddch(board_win, y, x, ch);
}

void space_view::show_board()
{
    char a = 'a';
    for (int k = 0; k < gamev.width_s(); k++)
    {
        this->addAt(0, k+1, '-');
    }
    for (int i = 0; i < gamev.height_s(); i++)
    {
        this->addAt(i+1, 0, '|');
        for (int k = 0; k < gamev.width_s(); k++)
        {
            a = gamev.get_field_info(i, k);
            this->addAt(i+1, k+1, a);
        }
        this->addAt(i+1, gamev.width_s()+1, '|');
    }
    for (int k = 0; k < gamev.width_s(); k++)
    {
        this->addAt(gamev.height_s()+1, k+1, '-');
    }
}

