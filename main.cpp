
#include "Screen.h"
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
    screen.update();

    SDL_Texture *sun = nullptr, *clap = nullptr;
    std::string Sun = "SunWithFace.bmp";
    std::string Clap = "Clap.bmp";
    sun = screen.LoadFile(Sun);
    clap = screen.LoadFile(Clap);

    int iW,iH;
    SDL_QueryTexture(sun, NULL,NULL, &iW, &iH);
    int x = screen.SCREEN_WIDTH / 2 - 60;
    int y = screen.SCREEN_HEIGHT / 2;
    screen.ApplySurface(x,y,sun, screen.renderer);
    SDL_RenderPresent(screen.renderer);

    int iW1,iH1;
    SDL_QueryTexture(clap, NULL,NULL, &iW1, &iH1);
    int x1 = screen.SCREEN_WIDTH / 2 + 60;
    int y1 = screen.SCREEN_HEIGHT / 2;
    screen.ApplySurface(x1,y1,clap, screen.renderer);
    SDL_RenderPresent(screen.renderer);

    std::cin.get();

    screen.close();
    SDL_Quit();

    printf("Quiting....\n");
  //  std::cin.get();
    return 0;
}
