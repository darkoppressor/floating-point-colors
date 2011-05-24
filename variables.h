/* Copyright (c) 2011 Kevin Wells */
/* Floating Point Colors may be freely redistributed.  See license for details. */

#ifndef variables_h
#define variables_h

#include <string>/**We are declaring a string variable.*/
#include <sstream>/**We are declaring a string stream.*/
#include <vector>

#include <SDL_ttf.h>

/**Screen dimensions and bpp:*/
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int SCREEN_BPP;

extern const float color_change;

extern float red;
extern float green;
extern float blue;

/**SDL Specific variables:*/
/**The surfaces that we will be using.*/
extern SDL_Surface *screen;
extern SDL_Surface *message;
/**Used to poll for events.*/
extern SDL_Event event;
/**The fonts that we will be using.*/
extern TTF_Font *font_42;
extern TTF_Font *font_30;
extern SDL_Color text_color;

extern std::stringstream ss;
extern std::string msg;

#endif
