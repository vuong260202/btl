#include "sound.h"

Mix_Music* music = NULL;
Mix_Chunk* chunk = NULL;

void initMix()
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    music = Mix_LoadMUS("music\\music.mp3");
    Mix_VolumeMusic(64);

    chunk = Mix_LoadWAV("music\\effect.mp3");
    Mix_VolumeChunk(chunk, 128);

    Mix_PlayMusic(music, -1);
}

void playMusic( bool k )
{
    if( k == 0 )
        Mix_PauseMusic();
    else
        Mix_ResumeMusic();
}

void effect()
{
    Mix_PlayChannel( -1, chunk, 0);
}
