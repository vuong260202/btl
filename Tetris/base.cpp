#include "base.h"
void base::render(SDL_Renderer* ren)
{
    render_khung( ren );

    for( int i = 1; i < lengH - 1; i++)
        for( int j = 1; j < lengW - 1; j++)
    //if(arr[i][j].empty == 0)
        renderRect( ren, arr[i][j].color, y + step * j,  x + step * i, step - 1, step - 1, !arr[i][j].empty);

    for( int i = 0; i < 4; i++)
        for( int j = 0; j < 4; j++)
    if( small.getArr(i, j) )
        {
            renderRect( ren, BLACK_COLOR, y + (small._y + j) * step, x + (small._x + i) * step, step , step , 1);
            renderRect( ren, small.getColor(), y + (small._y + j) * step, x + (small._x + i) * step, step - 1, step - 1, 1);
        }

}

void base::renderNextSmall( SDL_Renderer* ren )
{
    for( int i = 0; i < 3; i++ )
        nextSmall[i].render( ren , i );
}

void base::render_khung( SDL_Renderer* ren )
{
    for( int i = 0; i < lengH; i++ )
    {
        renderRect( ren, arr[i][lengW - 1].color, y + step * (lengW - 1),  x + step * i, step - 1, step - 1, 1);
        renderRect( ren, arr[i][0].color, y,  x + step * i, step - 1, step - 1, 1);
    }

    for( int j = 1; j < lengW - 1; j++ )
    {
        renderRect( ren, arr[lengH - 1][j].color, y + step * j,  x + step * (lengH - 1), step - 1, step - 1, 1);
        renderRect( ren, arr[0][j].color, y + step * j,  x, step - 1, step - 1, 1);
    }
}

void base::init()
{
    score = 0;

    for( int i = 1; i < lengH - 2; i++)
        for( int j = 1; j < lengW - 2; j++)  arr[i][j].empty = 1;

}

void base::init_khung()
{
    x = (height - lengH * step) / 2;
    y = (width - lengW * step) / 2;

    for( int i = 0; i < lengW; i++)
        arr[0][i].empty = arr[lengH-1][i].empty = 0;

    for( int i = 0; i < lengH; i++)
        arr[i][lengW-1].empty = arr[i][0].empty = 0;

    setColorKhung( RED_COLOR );
}


void base::setColorKhung(SDL_Color color)
{
    for( int i = 0; i < lengW; i++)
        arr[0][i].color = arr[lengH-1][i].color = color;

    for( int i = 0; i < lengH; i++)
        arr[i][lengW-1].color = arr[i][0].color = color;
}

void base::incScore( int _score )
{
    score += _score;
}

void base::update()
{
    small.setEmpty();
    for( int i = 0; i < 4; i++)
        for( int j = 0; j < 4; j++)
        if(arr[i + small._x][j + small._y].empty == true && small.getArr(i, j) ) {
                arr[i + small._x][j + small._y].empty = false;
                arr[i + small._x][j + small._y].color = small.getColor();
        }
}


bool base::xl_An()
{
    int cnt = 1, tmp = 0;
    bool K = 0;
    for( int i = lengH - 2; i > cnt; )
    {
        int k  = 0;
        for( int j = 1; j <= lengW - 2; j++) k += arr[i][j].empty;

        if( k == lengW - 2 ) {
                score += tmp;
                return K;
        }

        if( k == 0 ) {
            K = 1;

            tmp = (tmp * 1.1) - (int)(tmp * 1.1) % 10 + 100;
            lines++;
            for( int u = i; u > cnt; u-- )
                for( int j = 1; j < lengW - 1; j++ ) arr[u][j] = arr[u - 1][j];

            for( int j = 1; j <= lengW - 2; j++) arr[cnt][j].empty = 1;
            cnt++;
        } else i--;
    }
    score += tmp;
    return K;
}

void base::xl_Gop()
{
    if(small.Empty() == true) return;

    bool check = false;
    for( int i = 0; i < 4; i++)
        for( int j = 0; j < 4; j++)
            if( small.getArr(i, j) && arr[i + small._x + 1][j + small._y].empty == false ) check = true;
    if( check )
    {
        small.setEmpty(1);
        for( int i = 0; i < 4; i++)
        for( int j = 0; j < 4; j++)
            if( small.getArr(i, j) ){
            arr[i + small._x][j + small._y].empty = 0;
            arr[i + small._x][j + small._y].color = GREEN_COLOR;
        }

    }
}

bool base::xl_Cham( )
{

    for( int j = 0; j < 4; j++ )
    for( int i = 0; i < 4; i++ )
    if(small.getArr(i, j) && arr[i + small._x][j + small._y].empty == false) return false;
    return true;
}

void base::xl_Bien()
{
    while( small._y <= 0 && !xl_Cham() ) small._y++;
    while( small._y + 3 >= lengW - 1 && !xl_Cham() ) small._y--;

}


bool base::xl_Xoay()
{
    small.xoay();
    xl_Bien();

    if( !xl_Cham() ) {
        small.moveLeft();
        if( !xl_Cham() ) small.moveRight();
        else {
                return 1;
        }

    }

    if( !xl_Cham() ) {
        small.moveRight();
        if( !xl_Cham() ) small.moveLeft();
        else {
                return 1;
        }
    }

    if( !xl_Cham() ) {
        small._x--;
        if( !xl_Cham() ) small._x++;
        else {
                return 1;
        }
    }

    if(!xl_Cham())
        for(int k = 0; k < 3; k++) small.xoay();
    return 0;
}

void base::setSmall()
{
    small = nextSmall[0];
    init_nextSmall();


}

void base::init_nextSmall()
{

    nextSmall[0] = nextSmall[1];
    nextSmall[1] = nextSmall[2];
    nextSmall[2].init();
}

void base::setNextSmallXY( int x, int y)
{
    nextSmall[0].init();
    nextSmall[1].init();
    nextSmall[2].init();
    for( int i = 0 ; i < 3; i++ )
    nextSmall[i].set_XY( x, y );

}

bool base::check_GameOver( bool k )
{
    if(small._x > 0) return false;
    for( int i = 0; i < 4; i++)
            if( small.getArr(k, i) && arr[k][small._y + i].empty == false ) return true;
    return false;
}
