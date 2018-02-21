#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "Planet.h"
#include "Screen.h"
#include <vector>
#include <iostream>

class Screen;

class Universe // manager
{
public:
  const int SUN_X_COORDINATE = 500;
  const int SUN_Y_COORDINATE = 300;

private:

  //std::vector<Planet&> SolarSystem;
public:

  Universe() = default;
  void add_planet_to_the_buffer(Planet&, Uint32 color, Screen& scr);
  void add_orbit_to_the_buffer(Planet&, Screen& scr);
  ~Universe() = default;


};
#endif
