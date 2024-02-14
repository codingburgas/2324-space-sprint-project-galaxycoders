#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <iomanip>

const int windowWidth = 1600;
const int windowHeight = 900;


int main() {

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaxy Coders");
	window.setFramerateLimit(60);

	bool GameOn = false;

	

	//Start Game Text
	sf::Text StartGameText;
	sf::Text KeyPressText;
	sf::Text Score;

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
	StartGameText.setPosition(540, 10);
	StartGameText.setCharacterSize(100);
	StartGameText.setFillColor(sf::Color::White);

	KeyPressText.setString("Press Any Key To Start Game");
	KeyPressText.setFont(KeyPressFont);
	KeyPressText.setPosition(700, 140);
	KeyPressText.setCharacterSize(25);
	KeyPressText.setFillColor(sf::Color::White);


	float score = 0;
	Score.setString(std::to_string(score));
	Score.setFont(KeyPressFont);
	Score.setPosition(sf::Vector2f(600, 20));
	Score.setCharacterSize(80);
	Score.setFillColor(sf::Color::White);


	//Game Background
	sf::Texture mntnBackground;
	if (!mntnBackground.loadFromFile("assets/45908.jpg")) {
		std::cout << "Couldn't load mountain background" << std::endl;
	}

	sf::Sprite mntnSprite;
	sf::Vector2f mntnPosition(-70, 0);
	mntnSprite.setTexture(mntnBackground);
	mntnSprite.setScale(sf::Vector2f(0.22, 0.2));
	mntnSprite.setPosition(mntnPosition);

	float yBackgroundVel = 5;



	//Rocket Sprite
	sf::Texture Rocket;
	if (!Rocket.loadFromFile("assets/rocket-texture.png")) {
		std::cout << "Couldn't load rocket"<< std::endl;
	}
	
	sf::Sprite RocketSprite;
	sf::Vector2f RocketPosition(805, 620);
	float RocketRotation = 0;

	RocketSprite.setTexture(Rocket);
	RocketSprite.setPosition(RocketPosition);
	RocketSprite.setRotation(RocketRotation);
	RocketSprite.setScale(sf::Vector2f(2.5, 2.5));
	RocketSprite.setOrigin(sf::Vector2f(25, 50));

	float xRotationVel = 0.4f;
	float xRocketVelocity = 6;
	





	//Game Loop
	while(window.isOpen()){

		//Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			RocketPosition.x -= xRocketVelocity;
			if (RocketRotation > -35) {

				RocketRotation -= xRotationVel;

			}
			if (RocketRotation < -6 && xRocketVelocity < 15) {
				xRocketVelocity += 0.1f;
			}

			if (RocketRotation > 6) {
				xRocketVelocity -= 0.1f;
			}

			if (RocketRotation == 6 && RocketRotation < 0) {
				xRocketVelocity += 0.1f;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			RocketPosition.x += xRocketVelocity;
			if (RocketRotation < 35) {

				RocketRotation += xRotationVel;

			}
			if (RocketRotation > 6 && xRocketVelocity < 15) {
				xRocketVelocity += 0.1f;
			}

			if (RocketRotation < -6) {
				xRocketVelocity -= 0.1f;
			}

			if (RocketRotation == 6 && RocketRotation > 0) {
				xRocketVelocity += 0.1f;
			}

		}



		//Collision With Walls
		if (RocketPosition.x > 1840) {
			RocketPosition.x = -10;
		}

		else if (RocketPosition.x < -10) {
			RocketPosition.x = 1840;
		}

		else if (RocketPosition.x > 1840) {
			RocketPosition.x = -10;
		}

		else if (RocketPosition.x < -10) {
			RocketPosition.x = 1840;
		}
			
		RocketSprite.setPosition(RocketPosition);
		RocketSprite.setRotation(RocketRotation);


		//Draw
		window.clear();

		window.draw(mntnSprite);

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

				GameOn = true;
				break;

			}
		}

		if (GameOn == false) {

			window.draw(StartGameText);

			window.draw(KeyPressText);

		}

		if (GameOn == true) {
			if (yBackgroundVel < 40) {
				yBackgroundVel += 0.1f;
			}
			mntnPosition.y += yBackgroundVel;
			mntnSprite.setPosition(mntnPosition);

			score += 0.1f ;
			window.draw(Score);
			Score.setString(std::to_string(score));
		}

		window.draw(RocketSprite);

		window.display();
	}
}