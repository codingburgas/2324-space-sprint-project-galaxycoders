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


	//Game Text
	sf::Text StartGameText;
	sf::Text KeyPressText;
	sf::Text Score;
	sf::Text ScoreText;


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
	StartGameText.setPosition(483, -5);
	StartGameText.setCharacterSize(100);
	StartGameText.setFillColor(sf::Color::White);

	KeyPressText.setString("Press Any Key To Start Game");
	KeyPressText.setFont(KeyPressFont);
	KeyPressText.setPosition(630, 120);
	KeyPressText.setCharacterSize(25);
	KeyPressText.setFillColor(sf::Color::White);


	int score = 0;
	Score.setString(std::to_string(score));
	Score.setFont(KeyPressFont);
	Score.setPosition(sf::Vector2f(260, 20));
	Score.setCharacterSize(70);
	Score.setFillColor(sf::Color::White);

	ScoreText.setString("SCORE:");
	ScoreText.setFont(KeyPressFont);
	ScoreText.setPosition(sf::Vector2f(30, 20));
	ScoreText.setCharacterSize(70);
	ScoreText.setFillColor(sf::Color::White);



	//Game Background
	sf::Texture mntnBackground;
	if (!mntnBackground.loadFromFile("assets/45908.jpg")) {
		std::cout << "Couldn't load mountain background" << std::endl;
	}

	sf::Texture BlueSky;
	if (!BlueSky.loadFromFile("assets/background-1.png")) {
		std::cout << "Couldn't load sky background" << std::endl;
	}

	sf::Sprite mntnSprite;
	sf::Vector2f mntnPosition(-70, 0);
	mntnSprite.setTexture(mntnBackground);
	mntnSprite.setScale(sf::Vector2f(0.22, 0.2));
	mntnSprite.setPosition(mntnPosition);

	sf::Sprite SkySprite;
	sf::Vector2f skyPosition(0, -900);
	SkySprite.setTexture(BlueSky);
	SkySprite.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite.setPosition(skyPosition);

	sf::Sprite SkySprite2;
	sf::Vector2f skyPosition2(0, -1799);
	SkySprite2.setTexture(BlueSky);
	SkySprite2.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite2.setPosition(skyPosition2);

	float yBackgroundVel = 5;


	//Rocket Sprite
	sf::Texture Rocket;
	if (!Rocket.loadFromFile("assets/rocket-texture.png")) {
		std::cout << "Couldn't load rocket" << std::endl;
	}

	sf::Sprite RocketSprite;
	sf::Vector2f RocketPosition(810, 620);
	float RocketRotation = 0;

	RocketSprite.setTexture(Rocket);
	RocketSprite.setPosition(RocketPosition);
	RocketSprite.setRotation(RocketRotation);
	RocketSprite.setScale(sf::Vector2f(2.5, 2.5));
	RocketSprite.setOrigin(sf::Vector2f(25, 50));

	float xRotationVel = 0.8f;
	float xRocketVelocity = 8;

	sf::Clock ScoreTimer;


	//Game Loop
	while (window.isOpen()) {

		//Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			RocketPosition.x -= xRocketVelocity;
			if (RocketRotation > -35) {

				RocketRotation -= xRotationVel;

			}
			if (RocketRotation < -8 && xRocketVelocity < 25) {
				xRocketVelocity += 0.1f;
			}

			if (RocketRotation > 8) {
				xRocketVelocity -= 0.1f;
			}

			if (RocketRotation == 8 && RocketRotation < 0) {
				xRocketVelocity += 0.1f;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			RocketPosition.x += xRocketVelocity;
			if (RocketRotation < 35) {

				RocketRotation += xRotationVel;

			}
			if (RocketRotation > 8 && xRocketVelocity < 25) {
				xRocketVelocity += 0.1f;
			}

			if (RocketRotation < -8) {
				xRocketVelocity -= 0.1f;
			}

			if (RocketRotation == 8 && RocketRotation > 0) {
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

		if (skyPosition.y != 900) {
			window.draw(SkySprite);
		}
		else if (skyPosition.y <= -899 && skyPosition.y != 900) {
			window.draw(SkySprite2);
		}

		

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();

				GameOn = true;


				//Reset Button
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					GameOn = false;

					RocketPosition.x = 810;
					RocketSprite.setPosition(RocketPosition);

					RocketRotation = 0;
					RocketSprite.setRotation(RocketRotation);

					mntnPosition.y = 0;
					mntnSprite.setPosition(mntnPosition);

					skyPosition.y = -900;
					SkySprite.setPosition(skyPosition);

					yBackgroundVel = 5;

				}
				break;


			}
		}

		//Start Screen
		if (GameOn == false) {

			window.draw(StartGameText);

			window.draw(KeyPressText);

			sf::Time elapsed = ScoreTimer.restart();
		}


		//Game On Loop
		if (GameOn == true) {
			if (yBackgroundVel < 40) {
				yBackgroundVel += 0.1f;
			}
			mntnPosition.y += yBackgroundVel;
			mntnSprite.setPosition(mntnPosition);

			skyPosition.y += yBackgroundVel;
			SkySprite.setPosition(skyPosition);

			skyPosition2.y += yBackgroundVel;
			SkySprite2.setPosition(skyPosition2);


			sf::Time elapsed = ScoreTimer.getElapsedTime();

			score = elapsed.asSeconds() * 10;
			window.draw(Score);
			Score.setString(std::to_string(score));

			window.draw(ScoreText);
		}


		window.draw(RocketSprite);

		window.display();
	}
}