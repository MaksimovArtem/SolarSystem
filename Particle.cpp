#include "Particle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

Particle::Particle():x(0),y(0)
{
  speed = rand() / RAND_MAX;
  direction = 0;
}

void Particle::change_speed(double new_speed)
{
  speed = new_speed;
}

void Particle::change_direction(double new_direction)
{
  direction = new_direction;
}

void Particle::update()
{
  //smth
}

Particle::~Particle(){
  //??
}
