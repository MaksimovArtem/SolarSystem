
#include "Screen.h"
#include "Particle.h"
#include "Planet.h"
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
    Planet is_the_sun_a_planet(400,300,99999,50,0,0,0);
    screen.add_planet_to_the_buffer(is_the_sun_a_planet.x_coord,
                                    is_the_sun_a_planet.y_coord,
                                    is_the_sun_a_planet.planet_radius,
                                    0xFFFF00FF);

      std::cout<<"end init"<<std::endl;
    

    screen.update();


    std::cin.get();


    screen.close();
    SDL_Quit();

    std::cout << ("Quiting....\n");
  //  std::cin.get();
    return 0;
}
