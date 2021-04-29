#pragma once

#include "khoi.h"

class base{
public:
    int x, y;
    int score = 0;
    int lines = 0;
    bool isLevel = false;
    int level = -1;
    khoi small;
    khoi nextSmall[3];

    void init();
    void init_khung();
    void init_nextSmall();
    void setNextSmallXY( int , int );

    void incScore( int );

    void setColorKhung( SDL_Color );
    void setSmall();
    void update();

    void render( SDL_Renderer* );
    void render_khung( SDL_Renderer* );
    void render_Score( SDL_Renderer* );
    void renderNextSmall( SDL_Renderer* );

    bool xl_Cham();
    bool xl_An();
    void xl_Gop();
    bool xl_Xoay();
    bool check_GameOver(bool );
    void xl_Bien();
    void setMusic() {
        isMusic ^= 1;
    }
    bool getMusic() { return isMusic; }
private:
    node arr[lengH][lengW];
    node nex_khung[8][8];
    SDL_Texture* path = NULL;
    bool isMusic = 1;
};
