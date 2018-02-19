#include "Planet.h"

Planet::Planet(int x,int y, float mass, int radius, int orb_radius, int a_,int b_):
  x_coord(x),y_coord(y),planet_mass(mass),planet_radius(radius),
  orbit_radius(orb_radius), a(a_), b(b_)
{
  massive_of_particles = new Particle[COUNT_OF_PARTICLES];
}

void Planet::update()
{
  for(int i = 0;i < COUNT_OF_PARTICLES; i++)
  {
    massive_of_particles[i].update();
  }
}

Planet::~Planet()
{
  delete[] massive_of_particles;
}
