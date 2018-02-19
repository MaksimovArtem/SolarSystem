#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle
{
public:
  double x;
  double y;
private:
  double speed;
  double direction;
public:
  Particle();
  ~Particle();
  void change_speed(double);
  void change_direction(double);
  void update();
};
#endif//PARTICLE_H
