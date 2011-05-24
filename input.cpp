/* Copyright (c) 2011 Kevin Wells */
/* Floating Point Colors may be freely redistributed.  See license for details. */

#include "input.h"
#include "variables.h"
#include "quit.h"
#include "sdl.h"
#include "screen_draw.h"

using namespace std;

void input_game(){
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
            quit_game();
            break;
        }
    }
    Uint8 *keystates=SDL_GetKeyState(NULL);/**Get keystates.*/
    /**Handle input.*/
    //Red up.
    if(keystates[SDLK_r]){
        //keystates[SDLK_r]=NULL;
        red+=color_change;
        if(red>1.0)
        red=1.0;
    }
    //Red down.
    if(keystates[SDLK_e]){
        //keystates[SDLK_e]=NULL;
        red-=color_change;
        if(red<0.0)
        red=0.0;
    }
    //Red up slow.
    if(keystates[SDLK_t]){
        keystates[SDLK_t]=NULL;
        red+=color_change;
        if(red>1.0)
        red=1.0;
    }
    //Red down slow.
    if(keystates[SDLK_w]){
        keystates[SDLK_w]=NULL;
        red-=color_change;
        if(red<0.0)
        red=0.0;
    }

    //Green up.
    if(keystates[SDLK_g]){
        //keystates[SDLK_g]=NULL;
        green+=color_change;
        if(green>1.0)
        green=1.0;
    }
    //Green down.
    if(keystates[SDLK_f]){
        //keystates[SDLK_f]=NULL;
        green-=color_change;
        if(green<0.0)
        green=0.0;
    }
    //Green up slow.
    if(keystates[SDLK_h]){
        keystates[SDLK_h]=NULL;
        green+=color_change;
        if(green>1.0)
        green=1.0;
    }
    //Green down slow.
    if(keystates[SDLK_d]){
        keystates[SDLK_d]=NULL;
        green-=color_change;
        if(green<0.0)
        green=0.0;
    }

    //Blue up.
    if(keystates[SDLK_b]){
        //keystates[SDLK_b]=NULL;
        blue+=color_change;
        if(blue>1.0)
        blue=1.0;
    }
    //Blue down.
    if(keystates[SDLK_v]){
        //keystates[SDLK_v]=NULL;
        blue-=color_change;
        if(blue<0.0)
        blue=0.0;
    }
    //Blue up slow.
    if(keystates[SDLK_n]){
        keystates[SDLK_n]=NULL;
        blue+=color_change;
        if(blue>1.0)
        blue=1.0;
    }
    //Blue down slow.
    if(keystates[SDLK_c]){
        keystates[SDLK_c]=NULL;
        blue-=color_change;
        if(blue<0.0)
        blue=0.0;
    }
}
