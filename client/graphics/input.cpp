// Victor 2/20

#include "input.h"

int keys_held[323];
int sdl_quit;
int mouse_x, mouse_y;
int mouse_xvel, mouse_yvel;


void init_input() {
    memset(keys_held,0,sizeof(keys_held));
    sdl_quit = 0;
}

// gets input from the user

// does not handle: caps, control, fnction, option/alt, commmand, shift/tab??
void get_input() {
    SDL_Event event;

    // while clears the input queue. Thus, no lag!
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            sdl_quit = 1;
        }
        if (event.type == SDL_KEYUP) {  // any key is released
            if (event.key.keysym.sym < 323)
                keys_held[event.key.keysym.sym] = 0;

            if (event.key.keysym.sym == SDLK_UP) {
                view_mode.set_y_offvel(0);
            }

            if (event.key.keysym.sym == SDLK_DOWN) {
                view_mode.set_y_offvel(0);
            }

            if (event.key.keysym.sym == SDLK_LEFT) {
                view_mode.set_x_offvel(0);
            }

            if (event.key.keysym.sym == SDLK_RIGHT) {
                view_mode.set_x_offvel(0);
            }


        }
        if (event.type == SDL_KEYDOWN) {  // any key is pressed
            if (event.key.keysym.sym < 323)
                keys_held[event.key.keysym.sym] = 1;

            if (event.key.keysym.sym == SDLK_UP) {
                view_mode.set_y_offvel(-5);
            }

            if (event.key.keysym.sym == SDLK_DOWN) {
                view_mode.set_y_offvel(5);
            }

            if (event.key.keysym.sym == SDLK_LEFT) {
                view_mode.set_x_offvel(-5);
            }

            if (event.key.keysym.sym == SDLK_RIGHT) {
                view_mode.set_x_offvel(5);
            }

        }
        if (event.type == SDL_MOUSEMOTION) {
            mouse_x = event.motion.x;
            mouse_y = event.motion.y;

            mouse_xvel = event.motion.xrel;
            mouse_yvel = event.motion.yrel;
        }
    }
}
