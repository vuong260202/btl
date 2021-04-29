#include "BG1.h"
using namespace std;

int main(int argc, char* argv[])
{
    SDL_Window* win;
    SDL_Renderer* ren;

//----------------------------------------------


    srand(time(NULL));
    initSDL( win, ren );
    demo( ren );
//----------------------------------------------
    SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}












