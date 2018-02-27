#pragma once
#include <vector>
#include <SFML/Graphics/Color.hpp>
class Planet
{
	//private://->public for work Kapp
public:
	//for the planet
	int x_coord;
	int y_coord;
	double planet_mass;
	int planet_radius;
	const int COUNT_OF_PARTICLES = 2 * planet_radius * planet_radius + 4 * planet_radius + 1;//sheet

	
	//for the orbit
	double a;//  x^2 + y^2 = 1
	double b;//  a^2   b^2

			//std::vector<Planet&> Satellites;
	sf::Color color;

public:
	Planet(int x, int y, double m, int r, double a, double b, sf::Color);
	~Planet();
	
};