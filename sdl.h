/* Copyright (c) 2011 Kevin Wells */
/* Floating Point Colors may be freely redistributed.  See license for details. */

#ifndef sdl_h
#define sdl_h

#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>

GLuint surface_to_texture(SDL_Surface* optimized_image);

SDL_Surface *load_image(std::string filename);

GLuint load_texture(std::string filename);

/**x offset, y offset, source surface, destination surface, clipping SDL_Rect, change offsets to center source surface somewhere?*/
void apply_surface(float x,float y,float h,float w,GLuint source, SDL_Rect* surface_clip,int centered);

void msg_write(float a,float b,int font_size,std::string msg,int centered);

bool init_GL();/**Initialize all of the OpenGL specific stuff.*/

bool init();/**Initialize all of the SDL stuff.*/

bool load_files();

void clean_up();

#endif
