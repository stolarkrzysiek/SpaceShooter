#include "menu.hpp"
#include <ncurses.h>
#include <iostream>
using namespace std;

menu::menu(int height, int width)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    this->height=height;
    this->width=width;
    board_win = newwin(this->height+2, this->width+2, (yMax / 2) - (this->height / 2), (xMax / 2) - (this->width / 2));
    
}

void menu::refresh()
{
    wrefresh(board_win);
}

void menu::clear()
{
    wclear(board_win);
    addBoarder();
}

void menu::initialize()
{
    clear();
    refresh();
}

void menu::addBoarder()
{
    box(board_win, 0, 0);
}



void menu::show_menu()
{
    mvwprintw(board_win,1,1,"Imie i nazwisko: Krzysztof Stolarczyk ");
    mvwprintw(board_win,2,1,"Nr albumu: 59012");
    mvwprintw(board_win,3,1,"kod grupy: K01-03y");
    mvwprintw(board_win,4,1,"Nr projektu: 3");
    mvwprintw(board_win,5,1,"Tytul projektu: Spaceship");
    
    
    mvwprintw(board_win,9,1,"Wybierz rodzaj statku");
    mvwprintw(board_win,10,1,"1.type 1");
    mvwprintw(board_win,11,1,"2.type 2");
    
}

void menu::end(int score)
{
    //mvwprintw(board_win,height/2,(board_win->_maxx/2)-(4),"Game Over");
    //mvwprintw(board_win,(height/2)+2,(board_win->_maxx/2)-(4),"Score: %d", score);
    
    for (int k = 0; k < width; k++)
    {
        
        mvwaddch(board_win, 0, k+1, '-');
    }
    for (int i = 0; i < height; i++)
    {
        
        mvwaddch(board_win, i+1, 0, '|');

        mvwaddch(board_win, i+1, width+1, '|');
    }
    
    mvwprintw(board_win,height/2,(board_win->_maxx/2)-(4),"Game Over");
    mvwprintw(board_win,(height/2)+2,(board_win->_maxx/2)-(4),"Score: %d", score);
    
    for (int k = 0; k < width; k++)
    {
        mvwaddch(board_win, height+1, k+1, '-');
    }
}
