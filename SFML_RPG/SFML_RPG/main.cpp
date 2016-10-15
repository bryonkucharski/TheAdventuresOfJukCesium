#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

/*
https://www.youtube.com/watch?v=axIgxBQVBg0

time stamp 7:40 is important
you may need to copy some .dll files from one place to another inside where your git project is located.
so watching the video from 7:40 on is good to clear some stuff up.

also up top there is a drop down window with x64 x86 and configuration manager left to the compile and run button.
make sure the drop down window says x86

*/

int main()
{
	sf::RenderWindow window(sf::VideoMode(300, 300), "FUCK BIRDS!");
	sf::CircleShape shape(150.f);
	shape.setFillColor(sf::Color::Blue);
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setFillColor(sf::Color::Magenta);
	cout << "HAR HAR HAR";

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.draw(rectangle);
		window.display();
		//string coke = "COKE";
		//cout << coke; //bad idea to cout in a while statement
	}

	return 0;
}