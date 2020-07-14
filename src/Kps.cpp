#include <Kps.hpp>

Keys keys(sf::Keyboard::F1);

Kps::Kps(sf::Font &font)
: _max_kps(0), _act_kps(0)
{
	_text.setFont(font);
	_text.setPosition(10, 10);
}

void Kps::update()
{
	if (_clock.getElapsedTime().asSeconds() > 1)
	{
		_act_kps = 0;
		_clock.restart();
	}

	_act_kps += keys.getKeyCount();
	if (_act_kps > _max_kps) _max_kps = _act_kps;

	_text.setString
	(
		"Max KPS: " + std::to_string(_max_kps) + "\n" +
		"    KPS: " + std::to_string(_act_kps)
	);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) _max_kps = 0;
}

void Kps::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(_text, states);
}
