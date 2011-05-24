/* Copyright (c) 2011 Kevin Wells */
/* Floating Point Colors may be freely redistributed.  See license for details. */

#include "variables.h"

using namespace std;

/**Screen dimensions and bpp:*/
int SCREEN_WIDTH=800;
int SCREEN_HEIGHT=600;
int SCREEN_BPP=0;/**We set the screen's bpp to 0 to make it set to the current screen bpp of the computer.*/

const float color_change=0.001;

float red=0;
float green=0;
float blue=0;

/**SDL Specific variables:*/
/**The surfaces that we will be using.*/
SDL_Surface *screen=NULL;/**The screen surface.*/
SDL_Surface *message=NULL;/**This surface is used when rendering text.*/
/**Used to poll for events.*/
SDL_Event event;
/**The fonts that we will be using.*/
TTF_Font *font_42 = NULL;
TTF_Font *font_30 = NULL;
SDL_Color text_color={255,255,255};

stringstream ss("");/**String stream used to easily render ints and stuff as strings.*/
string msg="";/**ss passes its information into this string for output with msg_write.*/
