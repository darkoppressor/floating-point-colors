#include "quit.h"
#include "sdl.h"
#include "variables.h"

using namespace std;

void quit_game(){
    clean_up();

    exit(EXIT_SUCCESS);
}
