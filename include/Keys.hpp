#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <array>

struct Keys
{
	Keys(sf::Keyboard::Key keyExept): _keyExept(keyExept) {}

	//Retorna el numero de teclas que se encontraban precionadas al momento de llamar la función 
	int getKeyCount()
	{
		int n = 0;
		for (int keyIndex = 0; keyIndex < sf::Keyboard::KeyCount; keyIndex++)
		{
			//La tecla presionada en este momento
			bool key = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keyIndex);

			//Si x tecla es precionada y no fue precionada antes
			//Entonces el contador incrementa
			//Y su estado cambia a True
			if (key && !_keys[keyIndex] && keyIndex != _keyExept)
			{
				_keys[keyIndex] = true;
				n++;
			//De lo contrario si la tecla no se encuentra presionada entonces su estaso el False
			} else if (!key) _keys[keyIndex] = false;
		}
		return n;
	}

	//En este array se almacena las teclas presionadas
	std::array<bool, sf::Keyboard::KeyCount> _keys;
	int _keyExept;
};
