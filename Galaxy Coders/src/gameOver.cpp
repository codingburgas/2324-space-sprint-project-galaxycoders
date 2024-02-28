#include "gameOver.h"

void gameOver(sf::Text deathInfo[10], sf::Sprite &TextBoxSprite)
{
	sf::Texture TextBox;
	if (!TextBox.loadFromFile("assets/textbox.png")) {
		std::cout << "Couldn't load text box" << std::endl;
	}


	sf::Vector2f TextBoxPos(200, -100);
	TextBoxSprite.setTexture(TextBox);
	TextBoxSprite.setPosition(TextBoxPos);
	TextBoxSprite.setScale(sf::Vector2f(6, 6));


	sf::Text DyingText;
	sf::Text DyingResetText;


	sf::Font StartFont;
	sf::Font KGCPFont;

	if (!StartFont.loadFromFile("assets/Fonts/vtks-giz/vtks giz.ttf")) {
		std::cout << "Error!" << std::endl;
	}

	if (!KGCPFont.loadFromFile("assets/Fonts/kg-chasing-pavements/KGChasingPavements.ttf")) {
		std::cout << "Error!" << std::endl;
	}

	DyingText.setString("YOU DIED!");
	DyingText.setFont(KGCPFont);
	DyingText.setPosition(sf::Vector2f(670, 290));
	DyingText.setCharacterSize(65);
	DyingText.setFillColor(sf::Color::Black);

	DyingResetText.setString("Press Space To Reset");
	DyingResetText.setFont(KGCPFont);
	DyingResetText.setPosition(sf::Vector2f(550, 800));
	DyingResetText.setCharacterSize(50);
	DyingResetText.setFillColor(sf::Color::White);

	deathInfo[0].setString("The Higgs boson is an elementary particle predicted\n in the standard model of particle physics.");
	deathInfo[0].setFont(KGCPFont);
	deathInfo[0].setPosition(sf::Vector2f(360, 390));
	deathInfo[0].setCharacterSize(35);
	deathInfo[0].setFillColor(sf::Color::Black);

	deathInfo[1].setString("The Higgs boson's existence was predicted in 1964 by \nPeter Higgs, Francois Englert, Robert Brout, and \nother scientists.");
	deathInfo[1].setFont(KGCPFont);
	deathInfo[1].setPosition(sf::Vector2f(360, 390));
	deathInfo[1].setCharacterSize(35);
	deathInfo[1].setFillColor(sf::Color::Black);

	deathInfo[2].setString("The Higgs boson was discovered in experiments at \nthe Large Hadron Collider in 2012.");
	deathInfo[2].setFont(KGCPFont);
	deathInfo[2].setPosition(sf::Vector2f(360, 390));
	deathInfo[2].setCharacterSize(35);
	deathInfo[2].setFillColor(sf::Color::Black);

	deathInfo[3].setString("The Higgs boson is also known as the God particle \ndue to its crucial role in the structure of the \nUniverse.");
	deathInfo[3].setFont(KGCPFont);
	deathInfo[3].setPosition(sf::Vector2f(380, 390));
	deathInfo[3].setCharacterSize(35);
	deathInfo[3].setFillColor(sf::Color::Black);

	deathInfo[4].setString("The mass of the Higgs boson is about 125 \ngigaelectronvolts, with a spin of 0 and an \nelectric charge of 0.");
	deathInfo[4].setFont(KGCPFont);
	deathInfo[4].setPosition(sf::Vector2f(450, 390));
	deathInfo[4].setCharacterSize(35);
	deathInfo[4].setFillColor(sf::Color::Black);

	deathInfo[5].setString("The Higgs boson plays a crucial role in the \nmechanism of assigning mass to other particles, \nincluding hadrons and leptons.");
	deathInfo[5].setFont(KGCPFont);
	deathInfo[5].setPosition(sf::Vector2f(380, 390));
	deathInfo[5].setCharacterSize(35);
	deathInfo[5].setFillColor(sf::Color::Black);

	deathInfo[6].setString("The Higgs boson is part of the quantum field \nknown as the Higgs field, which fills the entire \nUniverse.");
	deathInfo[6].setFont(KGCPFont);
	deathInfo[6].setPosition(sf::Vector2f(380, 390));
	deathInfo[6].setCharacterSize(37);
	deathInfo[6].setFillColor(sf::Color::Black);

	deathInfo[7].setString("The Higgs boson can decay into other particles, \nallowing scientists to study its properties and \ninteractions.");
	deathInfo[7].setFont(KGCPFont);
	deathInfo[7].setPosition(sf::Vector2f(390, 390));
	deathInfo[7].setCharacterSize(35);
	deathInfo[7].setFillColor(sf::Color::Black);

	deathInfo[8].setString("The discovery of the Higgs boson helps us better \nunderstand the origin of the Universe and its early \nstages of development.");
	deathInfo[8].setFont(KGCPFont);
	deathInfo[8].setPosition(sf::Vector2f(360, 390));
	deathInfo[8].setCharacterSize(35);
	deathInfo[8].setFillColor(sf::Color::Black);

	deathInfo[9].setString("Understanding the Higgs boson opens up new perspectives for \nscientific research and technological developments, including \nthe creation of new methods for disease treatment and the \n                        development of new materials.");
	deathInfo[9].setFont(KGCPFont);
	deathInfo[9].setPosition(sf::Vector2f(360, 390));
	deathInfo[9].setCharacterSize(29);
	deathInfo[9].setFillColor(sf::Color::Black);
}