#pragma once

#include "text.h"


SDL_Texture* loadIMG(std::string  , SDL_Renderer* );
void showIMG(std::string , SDL_Renderer* , SDL_Rect );

void renderIMG( SDL_Renderer* , std::string , int , int );
void renderIMG( SDL_Renderer* , std::string , SDL_Rect );

void renderBG( SDL_Renderer* , int i1 = 0, int i2 = 0, int i3 = 0);
