#include "Screen.h"
#include <iostream>
#include <cstring>
#include <SDL2/SDL.h>


Screen::Screen():window(nullptr)//doesn't compile with nullptr?!
{};

void Screen::init_window()
{
  std::cout<<"init window: "<<std::endl;

  window = SDL_CreateWindow("system",
                      SDL_WINDOWPOS_CENTERED,
                      SDL_WINDOWPOS_CENTERED,
                      SCREEN_WIDTH,
                      SCREEN_HEIGHT,
                      SDL_WINDOW_SHOWN);
  //(name of window, positions of the window by x and y, needed screen width and height, some flag)

  if(window == nullptr)
  {
    std::cout<<"SDL_CreateWindow Error: "<<SDL_GetError()<<std::endl;
    SDL_Quit();
  }

  renderer = SDL_CreateRenderer(window,
                                -1,
                                SDL_RENDERER_PRESENTVSYNC);
  //(pointer on the window, -1 , flags)

  if(renderer == nullptr)
  {
    SDL_DestroyWindow(window);
    std::cout<<"SDL_CreateRenderer Error: "<<SDL_GetError()<<std::endl;
    SDL_Quit();
  }

  texture = SDL_CreateTexture(renderer,
                              SDL_PIXELFORMAT_RGBA8888,
                              SDL_TEXTUREACCESS_STATIC,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT);

  //(pointer on the renderer, TextureFormat, TextureAccess, width and height of the window)

  if(texture == nullptr)
  {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    std::cout<<"SDL_CreateRenderer Error: "<<SDL_GetError()<<std::endl;
    SDL_Quit();
  }

  buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
  buffer[SCREEN_WIDTH*SCREEN_HEIGHT] = 0xFFFFFFFF;

  std::cout<<"end init"<<std::endl;
};

void Screen::update()
{
  SDL_UpdateTexture(texture,
                    NULL,
                    buffer,
                    SCREEN_WIDTH * sizeof(Uint32));

  //(pointer on the texture, Rect structure to upd or NULL, pixel data to upd, number of bytes)
  SDL_RenderClear(renderer);

  SDL_RenderCopy(renderer,
                 texture,
                 NULL,
                 NULL);
  //(pointer on the renderer, pointer on the texture, source and destinations Rect struct or NULL's)

  SDL_RenderPresent(renderer);
}

void Screen::close()
{
  delete[] buffer;
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

SDL_Texture * Screen::LoadFile(std::string filename)
{
  SDL_Surface *loadedImage = nullptr;
  SDL_Texture *texture = nullptr;
  loadedImage = SDL_LoadBMP(filename.c_str());

  if(loadedImage == nullptr)
  {
    std::cout<<"Can't upload"<<SDL_GetError()<<std::endl;
  }
  else
  {
    texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
    SDL_FreeSurface(loadedImage);
  }
}

void Screen::ApplySurface(int x_coord,
                          int y_coord,
                          SDL_Texture *texture,
                          SDL_Renderer *renderer)
{
  sdl_Rect position;// (0;0) is top left corner
  // structure?! with 4 fields: x,y,w(idth), h(eight)
  position.x = x_coord;
  position.y = y_coord;
  SDL_QueryTexture(texture, NULL,NULL, &pos.w, &pos.h)
  SDL_RenderCopy(renderer, texture, NULL, &pos)

}
