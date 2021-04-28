#include "text.h"

void show( SDL_Renderer* ren, std::string text, SDL_Color color, int x, int y, int w, int h, int size)
{
    SDL_Rect dsc = {x, y, w, h};
    showText( ren , text, size, color, dsc);
}

void showText(SDL_Renderer* ren,std::string msg,const int size,SDL_Color color,SDL_Rect dsc)
{
    TTF_Font* font = TTF_OpenFont(PATH_FONT.c_str(),size);
    if(font == nullptr) std::cout<<SDL_GetError(),exit(2);
    SDL_Surface* load = TTF_RenderText_Solid(font,msg.c_str(),color);
    SDL_Texture* res = SDL_CreateTextureFromSurface(ren,load);

    int w,h;
    float tmp;
    SDL_QueryTexture(res,nullptr,nullptr,&w,&h);
    tmp = (h*1.0)/dsc.h;

    dsc.h = h;
    dsc.w *= tmp;

    SDL_RenderCopy(ren,res,nullptr,&dsc);

    SDL_FreeSurface(load);
    SDL_DestroyTexture(res);
    TTF_CloseFont(font);

    font = nullptr;
    load = nullptr;
    res = nullptr;
}
