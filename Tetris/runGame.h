#pragma once

#include "event.h"

void khung_game(SDL_Renderer* , base& );
int runGame(SDL_Renderer* , base );
void renderGame(SDL_Renderer* , base &) ;
bool PLAYGAME( base );

int renderStop( SDL_Renderer* , int , int );
bool renderOver( SDL_Renderer* , base );
