#ifndef PLANET_H
#define PLANET_H

#include "Particle.h"
#include <vector>
class Planet
{
//private://->public for work Kapp
public:
  //for the planet
  int x_coord;
  int y_coord;
  float planet_mass;
  int planet_radius;
  const int COUNT_OF_PARTICLES = 2 * planet_radius * planet_radius + 4 * planet_radius + 1;//sheet

  Particle *massive_of_particles;
  //for the orbit
  int orbit_radius;
  int a;//  x^2 + y^2 = 1
  int b;//  a^2   b^2

  //std::vector<Planet&> Satellites;

public:
  Planet(int x,int y,float m,int r,int o_r,int a,int b);
  ~Planet();
  void update();
};
#endif
