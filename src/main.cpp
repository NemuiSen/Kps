#include <Window.hpp>
#include <Kps.hpp>
#include <consola>

#ifdef DEBUG
int main()
#else
int WinMain()
#endif
{
	sf::Font font;
	if (!font.loadFromMemory(fileMemory.data, fileMemory.size))
	{
		cout << "Problema con la fuente" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	Window window({400, 100}, "Hey!");
	window << make_shared<Kps>(font);
	window.run();

	return 0;
}
