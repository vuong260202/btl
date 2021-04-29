#pragma once

#include "color.h"
#include <iostream>
#include <time.h>
#include <random>
#include <string>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "sound.h"

const int width = 1366;
const int height = 768;

const int step = 22;

const int lengW = 17;
const int lengH = 32;

const std::string PATH = "img\\renderIMG.PNG";
const std::string PATH_FONT = "font\\VNI-Korin.TTF";
const std::string IMG_MUSIC = "img\\music.png";
const std::string MUSIC_ON = "img\\on.png";
const std::string MUSIC_OFF = "img\\off.png";
const std::string IMG_NEN = "img\\IMG_BG.jpg";
const std::string IMG_STOP = "img\\IMG_STOP.png";
const std::string IMG_NEN_2 = "img\\IMG_BG1.png";

void setColor(SDL_Renderer* , SDL_Color );
void renderRect( SDL_Renderer* , SDL_Color , int , int  , int , int , bool);

void initSDL(SDL_Window* &, SDL_Renderer* &);

bool check_mouse( int , int , int , int , int , int );
