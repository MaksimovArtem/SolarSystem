#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Universe.h"
using namespace std;

int main(int argv, char** args) {

	srand(time(NULL));

	Universe uni;
	int N = 5;
	/*for (int rr = 0; rr < N; ++rr) {
		int m = (rand() % 4 + 1) * 1000000;
		int r = m / 1000000;
		float x = (float)((2 * ((2 * rand()) / RAND_MAX) - 1) * (rand() % 390));
		float y = (float)((2 * ((2 * rand()) / RAND_MAX) - 1) * (rand() % 290));
		//cout << "x and y " << setprecision (6) << x << ' ' << y << endl;

		float ax = (float)((2 * ((2 * rand()) / RAND_MAX) - 1) *
			(((2 * rand()) / RAND_MAX) - 1) * (rand() % 3999000 + 1000));
		float ay = (float)((2 * ((2 * rand()) / RAND_MAX) - 1) *
			(((2 * rand()) / RAND_MAX) - 1) * (rand() % 3999000 + 1000));
		//cout << "ax and ay " << setprecision (6) << ax << ' ' << ay << endl;
		Object* obj = new Object(m, r, x, y, ax, ay);
		uni.add(obj);
	}*/
	Object* sun = new Object(50000, 20, 0.0, 0.0, 0.0, 0.0);
	
	Object* earth = new Object(1, 5, 0.0, 100.0, -6000.0 , -2000.0);

	Object* nibiru = new Object(1, 3, 0.0, -50.0, 8000.0, 2000.0);

	Object* planet228 = new Object(1, 7, 150.0, 0.0, -2000.0, 4000.0);

	Object* planet1 = new Object(1, 4, 250.0, 0.0, -2000.0, 3000.0);

	uni.add(sun);
	uni.add(earth);
	uni.add(nibiru);
	uni.add(planet228);
	uni.add(planet1);


	sf::RenderWindow window(sf::VideoMode(800,600), "Gravity");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{

		uni.exist();

		sf::CircleShape shape(1, 1);

		for (int i = 0; i < N; ++i) {

			Object* obj = uni.getObject(i);
			float f = obj->radius / 1.0;

			shape.setRadius(f);
			shape.setPointCount(50);

			if (obj->radius == 20)
				shape.setFillColor(sf::Color::Yellow);
			else if (obj->radius == 5)
				shape.setFillColor(sf::Color::Green);
			else if (obj->radius == 7)
				shape.setFillColor(sf::Color::Blue);
			else if (obj->radius == 4)
				shape.setFillColor(sf::Color::Red);
			else
				shape.setFillColor(sf::Color::Cyan);

			shape.setPosition(400 - f + obj->x, 300 - f - obj->y);

			window.draw(shape);
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.display();
		//window.clear(sf::Color(1, 1, 1, 50));
	}

	cout << "BOOOM";

	return 0;
}