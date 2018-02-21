
#include "Screen.h"
#include "Particle.h"
#include "Planet.h"
#include "Universe.h"
#include "SDL2/SDL.h"
#include <cstdio>
#include <iostream>
#include <cstring>

int main() {

    printf("Initializing SDL.\n");

    if((SDL_Init(SDL_INIT_EVERYTHING)==-1)) {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }

    Screen screen;
    screen.init_window();

    Universe god;

    Planet is_the_sun_a_planet(god.SUN_X_COORDINATE,
                               god.SUN_Y_COORDINATE,
                               99999,
                               50,
                               0,
                               0);

    float b_for_the_earth = sqrt(201);

    Planet earth(600,
                 300,
                 4000,
                 15,
                 101.0,
                 b_for_the_earth);

    god.add_planet_to_the_buffer(is_the_sun_a_planet,
                                 0xFFFF00FF,//yellow
                                 screen);

    god.add_planet_to_the_buffer(earth,
                                 0x00FFFF10,//aqua
                                 screen);

      std::cout<<"end init"<<std::endl;


    screen.update();


    std::cin.get();


    screen.close();
    SDL_Quit();

    std::cout << ("Quiting....\n");
  //  std::cin.get();
    return 0;
}
