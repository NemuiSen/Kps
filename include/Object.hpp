#pragma once
#include <libs.hpp>

struct Object: public sf::Drawable
{
	Object() {}
	virtual void update() = 0;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override {}
};
