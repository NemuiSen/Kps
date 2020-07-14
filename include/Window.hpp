#pragma once
#include <Object.hpp>

struct Window {
	Window(sf::VideoMode mode, string title);
	void run();
	Window &operator<<(const shared_ptr<Object> &object)
	{
		_objetc.push_back(object);
		return *this;
	}
private:
	sf::RenderWindow _window;
	list<shared_ptr<Object>> _objetc;
};
