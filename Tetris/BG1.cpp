#include "BG1.h"



bool showPE( SDL_Renderer* ren , base screen )
{
    int x = screen.y + 5 * step;
    int y = screen.x + 10 * step;
    setColor( ren , BLACK_COLOR );

    SDL_Rect rt = {0, 0, width, height};
    renderIMG( ren, PATH, screen.y, screen.x);

    renderBG(ren , 1, 2, 3);

    screen.render_khung( ren );

    show( ren , "PLAY" , WHITE_COLOR, x + 10, y , 100 , 50, 48 );
    show( ren , "EXIT" , WHITE_COLOR, x + 10, y + 4 * step , 100 , 50, 48 );


    SDL_RenderPresent( ren );

    return event( 1, x, y);
}


void demo( SDL_Renderer* ren )
{
    base screen;
    screen.init_khung();

    if( showPE( ren , screen ) == false ) return;

    while( true )
    {
        screen.init();
        int k = runGame( ren, screen );
        if( k == 0 ) return;
        if( k == 2 )
            if( showPE( ren , screen ) == false ) return;
    }
}
