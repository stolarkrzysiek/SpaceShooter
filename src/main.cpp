#include <iostream>
#include "field.hpp"
#include "space.hpp"
#include "shiptype1.hpp"
#include "shiptype2.hpp"
#include "space_view.hpp"
#include "menu.hpp"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <ncurses.h>

using namespace std;




int main()
{

    using namespace std::chrono_literals;
    char choice;
    int ch;
    int score=0;
    initscr();
    noecho();
    refresh();
    menu a(40, 100);
    a.initialize();
    a.show_menu();
    a.refresh();
    choice=getch();
    
    space the_space(100, 40);
    spaceship *type;
    
    switch(choice)
    {
        case '1':
            type = new shiptype1(the_space);
            break;
    
        case '2':
            type = new shiptype2(the_space);
            break;
    }
    the_space.rock_gen();
    type->toggle_ship();
    
    initscr();
    refresh();
    space_view view(the_space, 40, 100);
    view.initialize();
    
   nodelay(stdscr, TRUE);
            for (;;)
            {
                if ((ch = getch()) != ERR)
                {
                    switch (ch)
                    {
                        case 'w':
                            type->move_u();
                            break;
                        case 's':
                            type->move_d();
                            break;
                        case 'a':
                            type->move_l();
                            break;
                        case 'd':
                            type->move_r();
                            break;
                        default:
                            break;
                    }
                }
            
            view.show_board();
            view.refresh();
            the_space.rock_gen();
            the_space.next_con_rock();
            std::this_thread::sleep_for(150ms);

            if (!the_space.game_status()){break;}
                
                score++;
            }
    
    a.initialize();
    refresh();
    a.end(score);
    a.refresh();
    curs_set(0);
    getch();
    
    return 0;
}

