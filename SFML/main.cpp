#include <SFML/Graphics.hpp>
#include "Planet.h"
#include <iostream>
#include <ctime>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Fucking System");



	//Planet(int x, int y, double m, int r, double a, double b, sf::Color);
	Planet sun(350, 250, 9999.0, 50, 0.0, 0.0, sf::Color(0xFFFF00FF));

	sf::CircleShape sh1(sun.planet_radius);
	sh1.setFillColor(sun.color);
	sh1.setPosition(sun.x_coord, sun.y_coord); 
	
	
	Planet merq(500, 285, 4000.0, 15, 0.0, 0.0, sf::Color(0xFF0000FF));
	sf::CircleShape sh2(merq.planet_radius);
	sh2.setFillColor(merq.color);
	sh2.setPosition(merq.x_coord, merq.y_coord);



	
	srand(time(0));
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	double m_x = 0, m_y = 0;
	double direction = (2 * 3.14 * rand()) / RAND_MAX;
	double speed = (0.04 * rand()) / RAND_MAX;
	speed *= speed;
	int i = 1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sh1);
		

		direction += i * 0.0003;

		double xspeed = speed * sin(direction);
		double yspeed = speed * cos(direction);
		i = rand() % 3;
		m_x += xspeed * i ;
		m_y += yspeed  * i;
		

		sh2.move(m_x, m_y);
		window.draw(sh2);
		window.display();
	}

	return 0;
}
