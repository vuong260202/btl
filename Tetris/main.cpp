#include "BG1.h"
using namespace std;

int main(int argc, char* argv[])
{
    SDL_Window* win;
    SDL_Renderer* ren;

//----------------------------------------------

    initSDL( win, ren );
    srand(time(NULL));


    demo( ren );
//----------------------------------------------
    SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}












