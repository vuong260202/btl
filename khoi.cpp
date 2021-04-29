#include "khoi.h"

void khoi::xoay()
{
    bool tmp[4][4];
    for( int i = 0; i < 4; i++)
        for( int j = 0; j < 4; j++)  tmp[i][j] = arr[3-j][i];

    for( int i = 0; i < 4; i++)
        for( int j = 0; j < 4; j++ )
            arr[i][j] = tmp[i][j];
}

void khoi::init()
{
    _x = 0; _y = 6;

    setEmpty( false );


    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) setArr(i, j, 0);

    int ran = ( rand() % 30 ) % 7;
    switch( ran ){
    case 0:
        setColor( YELLOW_COLOR );
        setArr(1, 1);setArr(2, 1);setArr(1, 2);setArr(2, 2, 1);
        break;
    case 1:
        setColor( BLUE_COLOR );
        for( int i = 0; i < 4; i++) setArr(1, i, 1);
        break;
    case 2:
        setColor( LIME_COLOR );
        setArr(1, 1, 1);setArr(1, 2, 1);setArr(2, 2, 1);setArr(2, 3, 1);
        break;
    case 3:
        setColor( ORANGE_COLOR );
        setArr(1, 1, 1);setArr(1, 2, 1);setArr(1, 3, 1);setArr(2, 2, 1);
        break;
    case 4:
        setColor( RED_COLOR );
        setArr(2, 1, 1);setArr(1, 2, 1);setArr(1, 3, 1);setArr(2, 2, 1);
        break;
    case 5:
        setColor( BLUE_COLOR );
        setArr(1, 1, 1);setArr(1, 2, 1);setArr(1, 3, 1);setArr(2, 1, 1);
        break;
    case 6:
        setColor( BLUE_COLOR );
        setArr(1, 1, 1);setArr(1, 2, 1);setArr(1, 3, 1);setArr(2, 3, 1);
        break;
    }
}

void khoi::increat()            { if(empty == false) _x++; }
void khoi::moveLeft()           { _y--;            }
void khoi::moveRight()          { _y++;            }
bool khoi::getArr(int i, int j) { return arr[i][j];}
void khoi::setEmpty()           { empty ^= 1;      }
bool khoi::Empty()              { return empty;    }
void khoi::setArr(int i, int j) { arr[i][j] ^= 1;   }
void khoi::setArr(int i, int j, bool k) { arr[i][j] = k;   }
void khoi::set_XY(int x, int y)       { _x2 = x; _y2 = y; }

void khoi::render(SDL_Renderer* ren, int k )
{
    for( int i = 0; i < 4; i++)
        for( int j = 0; j < 4; j++)
    if( arr[i][j] )
        renderRect( ren, color, _y2 + j * step , _x2 + i * step + 4 * k * step, step - 1, step - 1, 1);
}
