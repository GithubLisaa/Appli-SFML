#include <SFML/Graphics.hpp>
#include <iostream>

//c'est un snake si jamais...

sf::RenderWindow window(sf::VideoMode(1400, 800), "Snake");

struct vector2{
	int x;
	int y;
	vector2(int posX, int posY) : x(posX), y(posY){}
};

sf::Vector2f Vector2fSFML(const vector2& vec) {
	return sf::Vector2f(static_cast<float>(vec.x), static_cast<float>(vec.y));
}

int gamespeed = 100;
vector2 playerstartpose(500, 500);
sf::CircleShape playerhead(20);

void OnStart() {
	playerhead.setPosition(Vector2fSFML(playerstartpose)); //sinon utiliser sf::Vector2f(playerstartpose.x, playerstartpose.y)
}

void Affichage() {
	sf::sleep(sf::milliseconds(gamespeed));
	window.clear();
	window.draw(playerhead);
	window.display();
}

int main() {
	OnStart();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::KeyPressed
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
		Affichage();
	}
}