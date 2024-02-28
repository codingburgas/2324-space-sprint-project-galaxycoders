#include "gameOnText.h"

void gameOnText() {
	sf::Text Score;
	sf::Text ScoreText;
	sf::Text ResetText;

	sf::Font StartFont;
	sf::Font KGCPFont;

	if (!StartFont.loadFromFile("assets/Fonts/vtks-giz/vtks giz.ttf")) {
		std::cout << "Error!" << std::endl;
	}

	if (!KGCPFont.loadFromFile("assets/Fonts/kg-chasing-pavements/KGChasingPavements.ttf")) {
		std::cout << "Error!" << std::endl;
	}

	Score.setFont(KGCPFont);
	Score.setPosition(sf::Vector2f(260, 20));
	Score.setCharacterSize(70);
	Score.setFillColor(sf::Color::Yellow);

	ScoreText.setString("SCORE:");
	ScoreText.setFont(KGCPFont);
	ScoreText.setPosition(sf::Vector2f(30, 20));
	ScoreText.setCharacterSize(70);
	ScoreText.setFillColor(sf::Color::White);

	ResetText.setString("Press R To Reset");
	ResetText.setFont(KGCPFont);
	ResetText.setPosition(sf::Vector2f(600, 800));
	ResetText.setCharacterSize(50);
	ResetText.setFillColor(sf::Color::White);
}