/*#pragma once
#include "Planet.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics/Color.hpp>

class Universe // manager
{
public:
	const int SUN_X_COORDINATE = 500;
	const int SUN_Y_COORDINATE = 300;

private:

	std::vector<Planet&> SolarSystem;
public:

	Universe() = default;
	void add_planet(Planet&);
	//void add_orbit_to_the_buffer(Planet&);
	~Universe() = default;


};*/