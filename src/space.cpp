#include <iostream>
#include <vector>
#include "space.hpp"
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

space::space(int width, int height)
{
    for (int i = 0; i < width * height; i++)
    {
        field f;
        Board.push_back(f);
    }

    this->width = width;
    this->height = height;
}

field &space::at(int row, int col)
{
    return Board[(row * width) + col];
}

void space::show_space()
{
    vector<char> board_char;
    vector<char> board_row; //ilosc elementow vectora to width

    //int index=0;
    for (int i = 0; i < width * height - 1; i++)
    {
        if (Board[i].ship_con() == 's' && Board[i].rock_con() == 'r')
        {
            board_char.push_back('c');
        }
        else if (Board[i].ship_con() == 's')
        {
            board_char.push_back('s');
        }
        else if (Board[i].rock_con() == 'r')
        {
            board_char.push_back('r');
        }
        else
            board_char.push_back(' ');
    }

    /* while(index<width*height)
   {
    
          for(int i=0;i<width;i++)
          {
            board_row.push_back(board_char[index+i]);
          }
          string s(board_row.begin(), board_row.end());
          s=s+'\n';
          cout<<s;
         
         
         
        index=index+width;
        board_row.clear();
        
   }*/

    /* for(int i=0;i<width*height-1;i++)
   {
    cout<<board_char[i]<<board_row[i]<<endl;
   }*/

    /*for(int i=0; i<width*height; i++)
    {
        if(i%width==0) cout<<endl;
        cout<<"["<<Board[i].ship_con()<<","<<Board[i].rock_con()<<"]";
        
    }
    cout<<endl;*/
}

void space::change_ship_con(int row, int col) //zmiana statusu pola ship
{
    at(row, col).change_ship_con();
}

void space::change_rock_con(int row, int col) //zmiana statusu pola rock
{
    at(row, col).change_rock_con();
}

void space::rock_gen()
{

    int x = 0, y = 0;
    y = rand() % width / 30;
    //cout<<y;
    //cout<<rand() % l;
    for (int i = 0; i < y; i++)
    {
        x = rand() % width;
        this->change_rock_con(0, x);
    }
}

void space::next_con_rock()
{

    for (int i = (width * height) - width; i < width * height; i++)
    {
        if (Board[i].rock_con() == 'r')
        {
            Board[i].change_rock_con();
        }
        else
            continue;
    }
    for (int i = (width * height) - 1 - width; i >= 0; i--)
    {
        if (Board[i].rock_con() == 'r')
        {
            Board[i].change_rock_con();
            Board[i + width].change_rock_con();
        }
        else
            continue;
    }
}

int space::width_s()
{
    return this->width;
}

int space::height_s()
{
    return this->height;
}

bool space::game_status()
{
    for (int i = 0; i < width * height - 1; i++)
    {
        if (Board[i].ship_con() == 's' && Board[i].rock_con() == 'r')
        {
            return false;
        }
        else
            continue;
    }
    return true;
}

char space::get_field_info(int row, int col)
{
    if (at(row, col).ship_con() == 's' && at(row, col).rock_con() == 'r')
    {
        return 'X';
    }
    else if (at(row, col).ship_con() == 's')
    {
        return 's';
    }
    else if (at(row, col).rock_con() == 'r')
    {
        return 'r';
    }
    else
        return ' ';
}

