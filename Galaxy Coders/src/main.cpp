#include <iostream>
#include <SFML/Graphics.hpp>
#include "textures.cpp"
#include "physics.cpp"


const int windowWidth = 1000;
const int windowHeight = 800;

int main() {

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaxy Coders");
	window.setFramerateLimit(60);


	//Define Text and Fonts
	sf::Text StartGameText;
	sf::Text KeyPressText;

	sf::Font StartFont;
	sf::Font KeyPressFont;

	//Load Fonts
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



	sf::Texture Rocket;
	if (!Rocket.loadFromFile("assets/rocket-texture.png")) {
		std::cout << "Couldn't load rocket" << std::endl;
	}
	
	sf::Sprite RocketSprite;
	sf::Vector2f RocketPosition(470, 300);
	float RocketRotation = 0;

	RocketSprite.setTexture(Rocket);
	RocketSprite.setPosition(RocketPosition);
	RocketSprite.setRotation(RocketRotation);
	RocketSprite.setScale(sf::Vector2f(1.2, 1.2));


	float xRocketRotation = 1;
	float xRocketVelocity = 3;
	float yRocketVelocity = 3;
	
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


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				if (RocketRotation > 180) {

				RocketPosition.y += yRocketVelocity;
				}
				else {
					RocketPosition.y -= yRocketVelocity;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				RocketPosition.x -= xRocketVelocity;
				RocketRotation -= xRocketRotation;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				RocketPosition.x += xRocketVelocity;
				RocketRotation += xRocketRotation;
			}


		//physics
		RocketSprite.setRotation(RocketRotation);
		RocketSprite.setPosition(RocketPosition);



		window.clear(sf::Color::Black);

		window.draw(StartGameText);

		window.draw(KeyPressText);

		window.draw(RocketSprite);

		window.display();
	}
}