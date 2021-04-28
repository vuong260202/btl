#include "runGame.h"

bool PLAYGAME( base SC )
{
    SDL_Event e;

    while( !SDL_PollEvent(&e) );

    if( e.type == SDL_MOUSEBUTTONDOWN )
    {
        int x = e.button.x;
        int y = e.button.y;

        //if( x )
    }

    return 1;
}

int runGame(SDL_Renderer* ren , base screen)
{
    SDL_RenderClear( ren );
    int x = screen.y + 5 * step;
    int y = screen.x + 10 * step;
    setColor( ren , BLACK_COLOR );

    SDL_Rect rt = {0, 0, width, height};
    renderIMG( ren, PATH, screen.y, screen.x);

    renderBG(ren , 1, 2, 3);

    //screen.render_khung( ren );

    show( ren , "PLAY" , WHITE_COLOR, x + 10, y , 100 , 50, 48 );
    show( ren , "EXIT" , WHITE_COLOR, x + 10, y + 4 * step , 100 , 50, 48 );

    initMix();
    showIMG( IMG_MUSIC, ren, {240, 30, 50, 50});

    SDL_Event e;
    screen.init();
    screen.setNextSmallXY(screen.x + step, screen.y + 20 * step);

    bool isRunning = true;
    uint32_t oldTime = SDL_GetTicks();
    uint32_t timeX = SDL_GetTicks();
    uint32_t nowTime = oldTime;
    uint32_t Time = 800;
    int k;
    bool checkX = false;



    renderBG( ren );

    showText(ren , std::to_string(screen.score) , 60, WHITE_COLOR, {200, 180 , 30 * std::to_string(screen.score).size(), 100 } );
    showText(ren , std::to_string(screen.lines) , 60, WHITE_COLOR, {200, 580 , 30 * std::to_string(screen.lines).size(), 100 } );

    while( isRunning ) {

        if( screen.small.Empty() ) {
            screen.setSmall();
            if( screen.level < screen.score / 1000 && screen.level < 20 )
            {
                screen.level = screen.score / 800 ;
                renderBG( ren , 2);

                Time = 800 - 50 * screen.level;

                if ( screen.level < 20 )
                    showText( ren, std::to_string(screen.level) , 60, WHITE_COLOR, {200, 380, 30 * std::to_string(screen.level).size() , 100} );
                else
                    showText( ren, "Level MAX" , 60, WHITE_COLOR, {200, 380, 270 , 100} );
            }

            showIMG( "img\\img.png" , ren , {screen.y + 19 * step, screen.x, 7 * step , 14 * step} );
            screen.renderNextSmall( ren );
        }

        isRunning = !screen.check_GameOver( 1 );

        if( !isRunning ) break;
        k = 1;
        while( SDL_PollEvent(&e) )
        {
            switch( e.type )
             {
                case SDL_MOUSEBUTTONDOWN:
                    {
                        int x = e.button.x , y = e.button.y;
                        if( check_mouse(x, y, width - 2 * step, 0, 2*step, 2*step) ) // STOP
                            k = renderStop( ren , screen.y , screen.x );
                        else if(check_mouse(x, y, 300, 20, 100, 50)) {
                                screen.setMusic();
                                playMusic( screen.getMusic() );
                        }
                        break;
                    }

                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE) {
                            Mix_PauseMusic();
                            return 2;
                    }
                    else if((e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w)  )  {
                            if(SDL_GetTicks() - timeX >= 300 && checkX == false ) {
                                    if( !screen.xl_Xoay() ) effect();
                                    checkX = true;
                            }
                    }
                    else if(e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_a) {
                            screen.small.moveLeft();
                            if(!screen.xl_Cham())  screen.small.moveRight();
                            else effect();
                    }
                    else if(e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_d) {
                            screen.small.moveRight();
                            if(!screen.xl_Cham())  screen.small.moveLeft();
                            else effect();
                    }
                    else if(e.key.keysym.sym == SDLK_F4) screen.small.setEmpty();
                    else if(e.key.keysym.sym == SDLK_DOWN) Time = 50;
                    break;
                case SDL_KEYUP:
                    if( e.key.keysym.sym == SDLK_DOWN ) Time = 800 - 50 * screen.level;
                    if( e.key.keysym.sym == SDLK_UP ) checkX = false;
                    break;
                default: break;
            }
        }

        if( k != 1 ) return k + 1;

        nowTime = SDL_GetTicks();
        if(nowTime - oldTime >= Time){
                screen.xl_Gop();
                screen.small.increat();
                oldTime = nowTime;
        }

        renderGame( ren, screen);
        SDL_RenderPresent( ren );

        if(screen.small.Empty() == true){

            if( screen.check_GameOver(0) ) {
                    isRunning = false;
                    break;
                }

            if ( screen.xl_An() ){

                renderBG( ren , 1, 3);
                showText(ren , std::to_string(screen.score) , 60, WHITE_COLOR, {200, 180 , 30 * std::to_string(screen.score).size(), 100 } );
                showText(ren , std::to_string(screen.lines) , 60, WHITE_COLOR, {200, 580 , 30 * std::to_string(screen.lines).size(), 100 } );
            }

            renderGame( ren, screen );
            SDL_RenderPresent( ren );
        }
    }

    if( !isRunning )
        return renderOver( ren , screen );

}

void renderGame( SDL_Renderer* ren, base& screen )
{
    setColor( ren, BLACK_COLOR );

    /********************************************/

    showIMG( IMG_STOP, ren, {width - 2 * step, 0, 2*step, 2*step});
    showIMG( (screen.getMusic() ? MUSIC_ON:MUSIC_OFF ), ren, {300, 30, 100, 50});

    /********************************************/

    renderRect(ren , BLACK_COLOR , screen.y, screen.x, lengW * step , lengH * step, 1);
    screen.render( ren );
}

bool renderOver( SDL_Renderer* ren , base screen )
{
    SDL_RenderClear( ren );
    showIMG( IMG_NEN, ren, {0, 0, width, height});

    int sz = 28;

    int x = (width - sz * step) / 2;
    int y = height / 4;

    renderIMG( ren, "img\\abcd.png", { x - step, y, 28 * step , 300} );
    renderIMG( ren, "img\\IMG_BG2.png", { x - 2 * step, y + 15 * step + 5, 260 , 110} );
    renderIMG( ren, "img\\IMG_BG2.png", { x + 17 * step - 10, y + 15 * step + 5, 260 , 110} );

    showText( ren , "HIGH SCORE", 40, WHITE_COLOR, { x - step / 2, height / 4 + step         , 20 * 10, 50 } );
    showText( ren , "LEVEL"     , 40, WHITE_COLOR, { x - step / 2, height / 4 + 5 * step + 5 , 20 * 5 , 50 } );
    showText( ren , "LINES"     , 40, WHITE_COLOR, { x - step / 2, height / 4 + 9 * step + 10, 20 * 5 , 50 } );


    std::string path = std::to_string(screen.score);
    showText( ren , path        , 40, WHITE_COLOR, { x  + 20 * step - path.size() * 10, height / 4 + step, 20 * path.size(), 50 } );

    path = std::to_string(screen.level);
    showText(ren  , path   , 40, WHITE_COLOR, { x  + 20 * step - path.size() * 10, height / 4 + 5 * step + 5, 20 * path.size(), 50 } );

    path = std::to_string(screen.lines);
    showText( ren , path   , 40, WHITE_COLOR, {x  + 20 * step - path.size() * 10, height / 4 + 9 * step + 10 , 20 * path.size(), 50 } );

    show( ren , "NEW GAME" , WHITE_COLOR, x - step, y + 16 * step , 20 * 8 , 50, 48 );
    show( ren , "EXIT" , WHITE_COLOR, x + 20 * step + 15, y + 16 * step , 20 * 4 , 50, 48 );

    SDL_RenderPresent( ren );

    SDL_Event e;

    while( true)
    {
        while(SDL_PollEvent( &e ) ){
            if(e.type == SDL_KEYDOWN)
                if(e.key.keysym.sym == SDLK_ESCAPE ) return 0;

            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                int _x = e.button.x;
                int _y = e.button.y;

                if( _x > x - 2 * step && _x < x - 2 * step + 260 && _y > y + 15 * step + 5 && _y <  y + 15 * step + 5 + 110 ) return 1;
                if( _x > x + 17 * step && _x < x + 17 * step + 260 && _y > y + 15 * step + 5 && _y <  y + 15 * step + 5 + 110 ) return 0;
            }
        }
    }

}

int renderStop( SDL_Renderer* ren , int x , int y)
{
    Mix_PauseMusic();
    //setColor( ren , BLACK_COLOR );

    showIMG( IMG_NEN_2, ren, {x + step, y + step, 15 * step, 30 * step});

    x += 5 * step;
    y += 10 * step;

    show( ren , "RESUME" , WHITE_COLOR, x + 10 - 2 * step, y , 168 , 50, 48 );
    show( ren , "NEW GAME" , WHITE_COLOR, x + 10 - 3 * step, y + 4 * step , 200 , 50, 48 );
    show( ren , "EXIT" , WHITE_COLOR, x + 10, y + 8 * step , 100 , 50, 48 );


    SDL_RenderPresent( ren );

    return event( 2, x, y ) - 1;
}

