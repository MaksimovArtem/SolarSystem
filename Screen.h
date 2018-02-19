#ifndef SCREEN_H
#define SCREEN_H

#include  <SDL2/SDL.h>

#include  <string>

class Screen
{
public:
  const static int SCREEN_HEIGHT = 600;
  const static int SCREEN_WIDTH = 800;

public:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  Uint32 *buffer;

public:
  Screen();

  void init_window();
  void update();
  void close();
  void add_planet_to_the_buffer(int x, int y, int radius,Uint32 color);
  //if we want to use .bnp files;
  SDL_Texture* LoadFile(std::string);
  void ApplySurface(int x, int y, SDL_Texture*, SDL_Renderer*);
  //
  ~Screen()=default;
};
#endif//end of SCREEN_H
