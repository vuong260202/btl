#pragma once

#include "IMG.h"

struct node{
    bool empty = 1;
    SDL_Color color;
};

class khoi{
public:
    int _x, _y;

    void xoay();
    void init();
    void moveLeft();
    void moveRight();
    void increat();
    bool getArr( int , int );
    void setEmpty();
    bool Empty();
    void setArr( int , int );
    void setArr( int , int , bool);
    void setEmpty( bool k ) { empty = k; }
    void setColor( SDL_Color c ) { color = c; }
    SDL_Color getColor() { return color; }

    void set_XY(int , int );
    void render( SDL_Renderer* , int );
private:
    int _x2, _y2;
    bool arr[4][4];
    bool empty = true;
    SDL_Color color;
};
