#include <Window.hpp>

Window::Window(sf::VideoMode mode, string title)
: _window(mode, title)
{}

void Window::run()
{
	sf::Event event;
	while (_window.isOpen())
	{
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				_window.close();
		}
		_window.clear();
		for (auto &o: _objetc)
		{
			o->update();
			_window.draw(*o);
		}
		_window.display();
	}
}
