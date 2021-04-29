#include "event.h"

/** int event
    * 1 : play | new game
    * 0 : exit
    * 2 : resume
*/

/** k
    * 1 : BG dau tien khi vao game
    * 2 : BG khi pause game
    * 3 : BG khi thua
*/


int event( int k , int x , int y)
{
    SDL_Event e;
    while( true )
    {
        while( SDL_PollEvent(&e) )
        {
            switch(e.type)
            {
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE) return 0;

                case SDL_MOUSEBUTTONDOWN:
                    int _x = e.button.x;
                    int _y = e.button.y;

                    if( check_mouse( _x, _y, x + 10, y + 4 * step , 130 , 50 ) && k == 1 ) return 0; // EXIT
                    if( check_mouse( _x, _y, x + 10, y , 130 , 50 ) && k == 1 ) return 1; // PLAY

                    if( check_mouse( _x, _y, x + 10 - 2 * step, y , 220 , 53 ) && k == 2 ) {
                            Mix_ResumeMusic();
                            return 2; // RESUME
                    }
                    if( check_mouse( _x, _y, x + 10 - 3 * step, y + 4 * step , 260 , 50 ) && k == 2 ) return 1; // NEWGAME
                    if( check_mouse( _x, _y, x + 10, y + 8 * step , 120 , 50 ) && k == 2 ) return 0; // EXIT
            }
        }
    }
}
