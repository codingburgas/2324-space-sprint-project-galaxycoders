#include "startScreenText.h"

void startScreenText(sf::Text& StartGameText, sf::Text& KeyPressText) {
	sf::Font StartFont;
	sf::Font KGCPFont;

	if (!StartFont.loadFromFile("assets/Fonts/vtks-giz/vtks giz.ttf")) {
		std::cout << "Error!" << std::endl;
	}

	if (!KGCPFont.loadFromFile("assets/Fonts/kg-chasing-pavements/KGChasingPavements.ttf")) {
		std::cout << "Error!" << std::endl;
	}


	StartGameText.setString("Galaxy Coders");
	StartGameText.setFont(StartFont);
	StartGameText.setPosition(483, -5);
	StartGameText.setCharacterSize(100);
	StartGameText.setFillColor(sf::Color::White);

	KeyPressText.setString("Press Any Key To Start Game");
	KeyPressText.setFont(KGCPFont);
	KeyPressText.setPosition(630, 120);
	KeyPressText.setCharacterSize(25);
	KeyPressText.setFillColor(sf::Color::White);
}