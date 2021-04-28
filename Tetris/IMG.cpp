#include "IMG.h"

SDL_Texture* loadIMG(std::string path , SDL_Renderer* renderer)
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

    if ( loadedSurface == NULL )
        std::cout << "Error: IMG_Load() \n";
    else {
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );

        if( newTexture == NULL )
            std::cout << "Error: SDL_CreateTextureFromSurface() \n";
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;

}

void showIMG(std::string path, SDL_Renderer* renderer, SDL_Rect rect)
{
    SDL_Texture* text = loadIMG(path, renderer);
    SDL_RenderCopy(renderer, text, NULL, &rect);
    SDL_DestroyTexture( text );
    SDL_RenderPresent(renderer);
}

void renderIMG( SDL_Renderer* ren, std::string path, int x, int y)
{
    showIMG( path , ren ,  {0 , 0, width, height } );
}

void renderIMG( SDL_Renderer* ren, std::string path, SDL_Rect rt )
{
    showIMG( path , ren ,  rt );
}

void renderBG( SDL_Renderer* ren, int it_score, int it_level, int it_lines)
{
    if(it_score == 1 || it_level == 1 || it_lines == 1)
    {
        renderIMG( ren, "img\\tem3.png", {180, 100, 250, 170} );
        show( ren , "Score" , WHITE_COLOR, 200, 100, 200, 100, 60 );
    }


    if(it_score == 2 || it_level == 2 || it_lines == 2)
    {
        renderIMG( ren, "img\\tem3.png", {180, 300, 250, 170} );
        show( ren , "Level" , WHITE_COLOR, 200, 300, 200, 100, 60 );
    }


    if(it_score == 3 || it_level == 3 || it_lines == 3)
   {
       renderIMG( ren, "img\\tem3.png", {180, 500, 250, 170} );
       show( ren , "Lines" , WHITE_COLOR, 200, 500, 200, 100, 60 );
   }

}


