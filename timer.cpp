#include <SDL.h>

#include "timer.h"

using namespace std;

Timer::Timer(){
    /**Initializes the variables.*/
    start_ticks=0;
    paused_ticks=0;
    paused=false;
    started=false;
}

void Timer::start(){
    started=true;/**Start the timer.*/
    paused=false;/**Unpause the timer.*/
    start_ticks=SDL_GetTicks();/**Get the current clock time.*/
}

void Timer::stop(){
    started=false;/**Stop the timer.*/
    paused=false;/**Unpause the timer.*/
}

float Timer::get_ticks(){
    if(started==true){/**If the timer is running.*/
        if(paused==true){/**If the timer is paused.*/
            return paused_ticks;/**Return the number of ticks when the timer was paused.*/
        }
        else{
            return SDL_GetTicks()-start_ticks;/**Return the current time minus the start time.*/
        }
    }
    return 0.0f;/**If the timer isn't running.*/
}

void Timer::pause(){
    if(started==true && paused==false){/**If the timer is running and isn't already paused.*/
        paused=true;/**Pause the timer.*/
        paused_ticks=SDL_GetTicks()-start_ticks;/**Calculate the paused ticks.*/
    }
}

void Timer::unpause(){
    if(paused==true){/**If the timer is paused.*/
        paused=false;/**Unpause the timer.*/
        start_ticks=SDL_GetTicks()-paused_ticks;/**Reset the starting ticks.*/
        paused_ticks=0;/**Reset the paused ticks.*/
    }
}

bool Timer::is_started(){
    return started;
}

bool Timer::is_paused(){
    return paused;
}
