#include <SFML/Graphics.hpp>

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
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

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
		window.display();
	}

	return 0;
}