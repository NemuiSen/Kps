#pragma once
#include <Object.hpp>
#include <Keys.hpp>

class Kps: public Object
{
	sf::Clock _clock;
	sf::Text _text;
	int _max_kps;
	int _act_kps;
public:
	Kps(sf::Font &font);
	void update() override;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
