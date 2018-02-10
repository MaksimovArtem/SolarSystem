#include "Screen.h"
#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>


int main() {

    printf("Initializing SDL.\n");

    if((SDL_Init(SDL_INIT_EVERYTHING)==-1)) {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }

    Screen screen;
    screen.init_window();
    screen.update();
    SDL_Texture *sun = nullptr, *clap =nullptr;
    sun = LoadFile("SunWithFace.bmp");
    clap = LoadFile("Clap.bmp");

    int iW,iH;
    SDL_QueryTexture(sun, NULL,NULL, &iW, &iH);
    int x = SCREEN_WIDTH / 2 - 60;
    int y = SCREEN_Height / 2 - 60;
    ApplySurface(x,y,sun, renderer);
    SDL_RenderPresent(renderer);

    std::cin.get();

    screen.close();
    SDL_Quit();

    printf("Quiting....\n");
  //  std::cin.get();
    return 0;
}
