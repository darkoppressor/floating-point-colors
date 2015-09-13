/* Copyright (c) 2011 Kevin Wells */
/* Floating Point Colors may be freely redistributed.  See license for details. */

#include "screen_draw.h"
#include "variables.h"
#include "sdl.h"

using namespace std;

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);/**Clear the screen.*/

    glPushMatrix();

    //Bind the texture object.
    ///glBindTexture(GL_TEXTURE_2D,NULL);

    glTranslated(0,0,0);/**Move to offset.*/

    glColor4f(red,green,blue,1.0);/**Set color to white.*/

    glBegin(GL_QUADS);/**Start quad.*/
        /**Draw the square:*/
        glTexCoord2d(0,0);  glVertex3d(0,0,0);
        glTexCoord2d(1,0);  glVertex3d(800,0,0);
        glTexCoord2d(1,1);  glVertex3d(800,300,0);
        glTexCoord2d(0,1);  glVertex3d(0,300,0);
    glEnd();/**End quad.*/

    glPopMatrix();/**Reset.*/

    ss.clear();ss.str("");ss<<"Red: ";ss<<red;msg=ss.str();
    msg_write(340,450,42,msg,0);
    ss.clear();ss.str("");ss<<"Green: ";ss<<green;msg=ss.str();
    msg_write(340,500,42,msg,0);
    ss.clear();ss.str("");ss<<"Blue: ";ss<<blue;msg=ss.str();
    msg_write(340,550,42,msg,0);

    msg_write(80,310,30,"Less Red = e",0);
    msg_write(520,310,30,"r = More Red",0);

    msg_write(80,360,30,"Less Green = f",0);
    msg_write(520,360,30,"g = More Green",0);

    msg_write(80,410,30,"Less Blue = v",0);
    msg_write(520,410,30,"b = More Blue",0);

    SDL_GL_SwapBuffers();/**Update the screen.*/
}
