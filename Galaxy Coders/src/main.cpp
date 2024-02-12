#include <iostream>
#include <SFML/Graphics.hpp>


const int windowWidth = 1920;
const int windowHeight = 1080;


int main() {

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaxy Coders", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	bool GameOn = false;

	


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
	StartGameText.setPosition(705, 50);
	StartGameText.setCharacterSize(80);
	StartGameText.setFillColor(sf::Color::White);

	KeyPressText.setString("Press a Key To Start Game");
	KeyPressText.setFont(KeyPressFont);
	KeyPressText.setPosition(820, 150);
	KeyPressText.setCharacterSize(23);
	KeyPressText.setFillColor(sf::Color::White);




	//Game Background
	sf::Texture mntnBackground;
	if (!mntnBackground.loadFromFile("assets/45908.jpg")) {
		std::cout << "Couldn't load mountain background" << std::endl;
	}

	sf::Sprite mntnSprite;
	sf::Vector2f mntnPosition(-70, 0);
	mntnSprite.setTexture(mntnBackground);
	mntnSprite.setScale(sf::Vector2f(0.26, 0.24));
	mntnSprite.setPosition(mntnPosition);




	//Rocket Sprite
	sf::Texture Rocket;
	if (!Rocket.loadFromFile("assets/rocket-texture.png")) {
		std::cout << "Couldn't load rocket" << std::endl;
	}
	
	sf::Sprite RocketSprite;
	sf::Vector2f RocketPosition(965, 770);
	float RocketRotation = 0;

	RocketSprite.setTexture(Rocket);
	RocketSprite.setPosition(RocketPosition);
	RocketSprite.setRotation(RocketRotation);
	RocketSprite.setScale(sf::Vector2f(2.5, 2.5));
	RocketSprite.setOrigin(sf::Vector2f(25, 50));

	float xRotationVel = 0.4f;
	float xRocketVelocity = 8;
	



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
			mntnPosition.y -= 1;
		}

		window.draw(RocketSprite);

		window.display();
	}
}