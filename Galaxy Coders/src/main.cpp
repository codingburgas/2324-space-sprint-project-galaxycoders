#include<iostream>
#include<SFML/Graphics.hpp>

int main() {
	const int windowWidth = 1000;
	const int windowHeight = 800;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaxy Coders");


	sf::Text StartGameText;
	sf::Text KeyPressText;

	sf::Font StartFont;
	sf::Font KeyPressFont;

	if (!StartFont.loadFromFile("resources/Fonts/vtks-giz/vtks giz.ttf")) {
		std::cout << "Error!";
	}

	if (!KeyPressFont.loadFromFile("resources/Fonts/kg-chasing-pavements/KGChasingPavements.ttf")) {
		std::cout << "Error!";
	}

	StartGameText.setString("Galaxy Coders");
	StartGameText.setFont(StartFont);
	StartGameText.setCharacterSize(80);
	StartGameText.setFillColor(sf::Color::White);
	StartGameText.setPosition(240, 270);

	KeyPressText.setString("Press a Key To Start Game");
	KeyPressText.setFont(KeyPressFont);
	KeyPressText.setCharacterSize(23);
	KeyPressText.setFillColor(sf::Color::White);
	KeyPressText.setPosition(350, 370);
	
	

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear(sf::Color::Black);

		window.draw(StartGameText);

		window.draw(KeyPressText);

		window.display();
	}
}