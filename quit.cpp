/* Copyright (c) 2011 Kevin Wells */
/* Floating Point Colors may be freely redistributed.  See license for details. */

#include "quit.h"
#include "sdl.h"
#include "variables.h"

using namespace std;

void quit_game(){
    clean_up();

    exit(EXIT_SUCCESS);
}
