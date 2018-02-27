#include "Planet.h"

Planet::Planet(int x, int y, double mass, int radius, double a_, double b_, sf::Color color_) :
	x_coord(x), y_coord(y), planet_mass(mass), planet_radius(radius),
	a(a_), b(b_), color(color_)
{
	
}



Planet::~Planet()
{
	
}