#ifndef SCREEN_H
#define SCREEN_H

#include  <SDL2/SDL.h>
#include  <cstring>

class Screen
{
public:
  const static int SCREEN_HEIGHT = 600;
  const static int SCREEN_WIDTH = 800;
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  Uint32 *buffer;

public:
  Screen();

  void init_window();
  void update();
  void close();

  //if we want to use .bnp files
  SDL_Texture* LoadFile(std::string filename);
  void ApplySurface(int x, int y, SDL_Texture *texture, SDL_Renderer *renderer);

  ~Screen()=default;
};
#endif//end of SCREEN_H
