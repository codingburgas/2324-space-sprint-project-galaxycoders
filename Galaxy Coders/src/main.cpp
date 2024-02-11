#include <iostream>
#include <SFML/Graphics.hpp>
#include "textures.cpp"
#include "physics.cpp"


const int windowWidth = 1240;
const int windowHeight = 720;


int main() {

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaxy Coders");
	window.setFramerateLimit(60);




	//Start Game Text
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
	StartGameText.setPosition(355, 270);
	StartGameText.setCharacterSize(80);
	StartGameText.setFillColor(sf::Color::White);

	KeyPressText.setString("Press a Key To Start Game");
	KeyPressText.setFont(KeyPressFont);
	KeyPressText.setPosition(475, 370);
	KeyPressText.setCharacterSize(23);
	KeyPressText.setFillColor(sf::Color::White);




	//Rocket Sprite
	sf::Texture Rocket;
	if (!Rocket.loadFromFile("assets/rocket-texture.png")) {
		std::cout << "Couldn't load rocket" << std::endl;
	}
	
	sf::Sprite RocketSprite;
	sf::Vector2f RocketPosition(615, 330);
	float RocketRotation = 0;

	RocketSprite.setTexture(Rocket);
	RocketSprite.setPosition(RocketPosition);
	RocketSprite.setRotation(RocketRotation);
	RocketSprite.setScale(sf::Vector2f(1.5, 1.5));
	RocketSprite.setOrigin(sf::Vector2f(25, 50));

	float xRotationVel = 0.2f;
	float xRocketVelocity = 3;
	

	//Game Loop
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
				break;
			}
		}


		
		//Movement

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			RocketPosition.x -= xRocketVelocity;
			if (RocketRotation > -35) {

				RocketRotation -= xRotationVel;

			}
			if (RocketRotation < -1 && xRocketVelocity < 15) {
				xRocketVelocity += 0.1f;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			RocketPosition.x += xRocketVelocity;
			if (RocketRotation < 35) {

				RocketRotation += xRotationVel;

			}
			if (RocketRotation > 1 && xRocketVelocity < 15) {
				xRocketVelocity += 0.1f;
			}
		}






		//Collision With Walls
		if (RocketPosition.x > 1180) {
			RocketPosition.x = -10;
		}

		if (RocketPosition.x < -10) {
			RocketPosition.x = 1180;
		}

		if (RocketPosition.x > 1180) {
			RocketPosition.x = -10;
		}

		if (RocketPosition.x < -10) {
			RocketPosition.x = 1180;
		}
			

		
		RocketSprite.setPosition(RocketPosition);
		RocketSprite.setRotation(RocketRotation);


		window.clear(sf::Color::Black);

		window.draw(StartGameText);

		window.draw(KeyPressText);

		window.draw(RocketSprite);

		window.display();
	}
}