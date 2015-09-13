/* Copyright (c) 2011 Kevin Wells */
/* Floating Point Colors may be freely redistributed.  See license for details. */

#include <vector>
#include <ctime>

#include <SDL.h>/**Standard SDL stuff.*/
#include <SDL_ttf.h>/**SDL true type font stuff.*/
#include <SDL_image.h>/**SDL graphics stuff.*/

#include "main.h"
#include "timer.h"
#include "variables.h"
#include "input.h"
#include "screen_draw.h"
#include "sdl.h"
#include "quit.h"

using namespace std;

void game_loop(){
    SDL_EnableKeyRepeat(1,0);
    bool loop=true;

    Timer delta;
    delta.start();/**Start the delta timer.*/

    while(loop==true){
        input_game();/**Handle input.*/
        delta.start();/**Restart delta timer.*/
        draw();/**Render the screen.*/
    }
}

int main(int argc, char* args[]){/**We want to use main this way because SDL doesn't like other ways of using main.*/
    /**The following two lines seed the random number generator.*/
    time_t seconds;
    srand((unsigned int)time(&seconds));

    /**Initiation of SDL stuff.*/
    if(init()==false){
        return 1;
    }
    if(load_files()==false){
        return 1;
    }
    game_loop();
    quit_game();
    return 0;
}
