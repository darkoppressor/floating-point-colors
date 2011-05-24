/* Copyright (c) 2011 Kevin Wells */
/* Floating Point Colors may be freely redistributed.  See license for details. */

#include "sdl.h"
#include "variables.h"

using namespace std;

GLuint surface_to_texture(SDL_Surface* optimized_image){
    GLuint texture;
    GLenum texture_format;
    GLint nOfColors;
    nOfColors=optimized_image->format->BytesPerPixel;
    if(nOfColors==4){/**If the image contains an alpha channel.*/
        if(optimized_image->format->Rmask==0x000000ff){
            texture_format=GL_RGBA;
        }
        else{
            texture_format=GL_BGRA;
        }
    }
    else if(nOfColors==3){/**If the image contains no alpha channel.*/
        if(optimized_image->format->Rmask==0x000000ff){
            texture_format=GL_RGB;
        }
        else{
            texture_format=GL_BGR;
        }
    }
    else{
        printf("Warning: the loaded image is not truecolor... this will probably break\n");
        //Do something about this.
    }
    glGenTextures(1,&texture);/**Have OpenGL generate a texture object handle for us.*/
    glBindTexture(GL_TEXTURE_2D,texture);/**Bind the texture object.*/
    /**Set the texture's properties:*/
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    /**Edit the texture object's image data using the information SDL_Surface gives us:*/
    glTexImage2D(GL_TEXTURE_2D,0,nOfColors,optimized_image->w,optimized_image->h,0,texture_format,GL_UNSIGNED_BYTE,optimized_image->pixels);
    return texture;
}

SDL_Surface *load_image(string filename){
    SDL_Surface* loaded_image=NULL;/**Temporary storage for the image being loaded.*/
    SDL_Surface* optimized_image=NULL;/**The optimized image that will be used.*/
    loaded_image=IMG_Load(filename.c_str());/**Load the image.*/
    if(loaded_image != NULL){/**Make sure nothing went wrong loading the image.*/
        optimized_image=SDL_DisplayFormatAlpha(loaded_image);/**Create the optimized image.*/
        SDL_FreeSurface(loaded_image);/**Free the old surface.*/
    }
    return optimized_image;
}

/**Call this when loading image files to be used as textures throughout the program:*/
GLuint load_texture(string filename){
    SDL_Surface* temp_surface=load_image(filename);
    GLuint temp_texture=surface_to_texture(temp_surface);
    SDL_FreeSurface(temp_surface);
    return temp_texture;
}

/**x offset, y offset, source surface, destination surface, clipping SDL_Rect, change offsets to center source surface somewhere?*/
void apply_surface(float x,float y,float w,float h, GLuint source, SDL_Rect* surface_clip = NULL,int centered=0){
    if(centered==1){
        x=(SCREEN_WIDTH-w)/2;
    }
    glBindTexture(GL_TEXTURE_2D,source);/**Bind the source texture.*/
    glTranslatef(x,y,0);/**Move to the offset of the image we want to place.*/
    glColor4f(1.0,1.0,1.0,1.0);/**This makes alpha blending work.*/
    glBegin(GL_QUADS);/**Start quad.*/
        /**Apply the texture to the screen:*/
        glTexCoord2i(0,0); glVertex3f(0,0,0);
        glTexCoord2i(1,0); glVertex3f(w,0,0);
        glTexCoord2i(1,1); glVertex3f(w,h,0);
        glTexCoord2i(0,1); glVertex3f(0,h,0);
    glEnd();/**End quad.*/
    glLoadIdentity();/**Reset.*/
}

void msg_write(float a,float b,int font_size,string msg,int centered=0){
    SDL_Surface* message=NULL;
    SDL_Surface* message_optimized=NULL;
    if(font_size==42){
        message=TTF_RenderText_Solid(font_42,msg.c_str(),text_color);
    }
    if(font_size==30){
        message=TTF_RenderText_Solid(font_30,msg.c_str(),text_color);
    }
    message_optimized=SDL_DisplayFormatAlpha(message);/**Create the optimized image.*/
    SDL_FreeSurface(message);/**Free the old surface.*/
    GLuint message_texture=surface_to_texture(message_optimized);
    if(centered!=0){
        apply_surface(a,b,message_optimized->w,message_optimized->h,message_texture,NULL,centered);
    }
    else{
        apply_surface(a,b,message_optimized->w,message_optimized->h,message_texture,NULL,0);
    }
    SDL_FreeSurface(message_optimized);
    glDeleteTextures(1,&message_texture);
}

bool init_GL(){
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0,0,0,0);/**Set clear color.*/
    glViewport(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    /**Set projection:*/
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,SCREEN_WIDTH,SCREEN_HEIGHT,0,-1,1);
    /**Initialize modelview matrix:*/
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(glGetError()!=GL_NO_ERROR){/**If there were any errors.*/
        return false;
    }
    return true;/**If everything initialized successfully, we are good to go!*/
}

/**Here we initialize all of the SDL stuff.*/
bool init(){
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1){/**Initialize all of the standard SDL stuff, and return false if it did not initialize properly.*/
        printf("Unable to init SDL: %s\n",SDL_GetError());
        return false;
    }
    if(TTF_Init()==-1){/**Initialize the SDL_ttf stuff, and return false if it did not initialize properly.*/
        printf("Unable to init SDL_ttf: %s\n",TTF_GetError());
        return false;
    }
    /**Set OpenGL attributes:*/
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    /**Set up the screen:*/
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_OPENGL|SDL_HWSURFACE);
    if(!screen){/**Return false if the screen could not be set up.*/
        printf("Unable to set video mode: %s\n",SDL_GetError());
        return false;
    }
    /**Initialize OpenGL*/
    if(init_GL()==false){
        return false;
    }
    SDL_WM_SetCaption("Floating Point Colors",NULL);/**Set the window caption.*/
    SDL_ShowCursor(1);/**Show the mouse cursor.*/
    return true;
}

bool load_files(){
    /**Load the font:*/
    font_42=TTF_OpenFont("Vera.ttf",42);
    if(!font_42){
        printf("Unable to load font: %s\n",TTF_GetError());
        return false;
    }
    font_30=TTF_OpenFont("Vera.ttf",30);
    if(!font_30){
        printf("Unable to load font: %s\n",TTF_GetError());
        return false;
    }
    return true;
}

void clean_up(){
    TTF_CloseFont(font_42);
    font_42=NULL;
    TTF_CloseFont(font_30);
    font_30=NULL;
    TTF_Quit();
    SDL_Quit();
    printf("Exited cleanly!\n");
}
