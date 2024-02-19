#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

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
	sf::Text ResetText;

	sf::Font StartFont;
	sf::Font KGCPFont;

	if (!StartFont.loadFromFile("resources/Fonts/vtks-giz/vtks giz.ttf")) {
		std::cout << "Error!" << std::endl;
	}

	if (!KGCPFont.loadFromFile("resources/Fonts/kg-chasing-pavements/KGChasingPavements.ttf")) {
		std::cout << "Error!" << std::endl;
	}

	//Start Screen Text
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

	//GameOn Text
	int score = 0;
	Score.setString(std::to_string(score));
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
	sf::Vector2f skyPosition2(0, -1800);
	SkySprite2.setTexture(BlueSky);
	SkySprite2.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite2.setPosition(skyPosition2);

	sf::Sprite SkySprite3;
	sf::Vector2f skyPosition3(0, -2700);
	SkySprite3.setTexture(BlueSky);
	SkySprite3.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite3.setPosition(skyPosition3);

	sf::Sprite SkySprite4;
	sf::Vector2f skyPosition4(0, -3600);
	SkySprite4.setTexture(BlueSky);
	SkySprite4.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite4.setPosition(skyPosition4);

	sf::Sprite SkySprite5;
	sf::Vector2f skyPosition5(0, -4500);
	SkySprite5.setTexture(BlueSky);
	SkySprite5.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite5.setPosition(skyPosition5);

	sf::Sprite SkySprite6;
	sf::Vector2f skyPosition6(0, -5400);
	SkySprite6.setTexture(BlueSky);
	SkySprite6.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite6.setPosition(skyPosition6);

	sf::Sprite SkySprite7;
	sf::Vector2f skyPosition7(0, -6300);
	SkySprite7.setTexture(BlueSky);
	SkySprite7.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite7.setPosition(skyPosition7);

	sf::Sprite SkySprite8;
	sf::Vector2f skyPosition8(0, -7200);
	SkySprite8.setTexture(BlueSky);
	SkySprite8.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite8.setPosition(skyPosition8);

	sf::Sprite SkySprite9;
	sf::Vector2f skyPosition9(0, -8100);
	SkySprite9.setTexture(BlueSky);
	SkySprite9.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite9.setPosition(skyPosition9);

	sf::Sprite SkySprite10;
	sf::Vector2f skyPosition10(0, -9000);
	SkySprite10.setTexture(BlueSky);
	SkySprite10.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite10.setPosition(skyPosition10);

	sf::Sprite SkySprite11;
	sf::Vector2f skyPosition11(0, -9900);
	SkySprite11.setTexture(BlueSky);
	SkySprite11.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite11.setPosition(skyPosition11);

	sf::Sprite SkySprite12;
	sf::Vector2f skyPosition12(0, -10800);
	SkySprite12.setTexture(BlueSky);
	SkySprite12.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite12.setPosition(skyPosition12);

	sf::Sprite SkySprite13;
	sf::Vector2f skyPosition13(0, -11700);
	SkySprite13.setTexture(BlueSky);
	SkySprite13.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite13.setPosition(skyPosition13);

	sf::Sprite SkySprite14;
	sf::Vector2f skyPosition14(0, -12600);
	SkySprite14.setTexture(BlueSky);
	SkySprite14.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite14.setPosition(skyPosition14);

	sf::Sprite SkySprite15;
	sf::Vector2f skyPosition15(0, -13500);
	SkySprite15.setTexture(BlueSky);
	SkySprite15.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite15.setPosition(skyPosition15);

	sf::Sprite SkySprite16;
	sf::Vector2f skyPosition16(0, -14400);
	SkySprite16.setTexture(BlueSky);
	SkySprite16.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite16.setPosition(skyPosition16);

	sf::Sprite SkySprite17;
	sf::Vector2f skyPosition17(0, -15300);
	SkySprite17.setTexture(BlueSky);
	SkySprite17.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite17.setPosition(skyPosition17);

	sf::Sprite SkySprite18;
	sf::Vector2f skyPosition18(0, -16200);
	SkySprite18.setTexture(BlueSky);
	SkySprite18.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite18.setPosition(skyPosition18);

	sf::Sprite SkySprite19;
	sf::Vector2f skyPosition19(0, -17100);
	SkySprite19.setTexture(BlueSky);
	SkySprite19.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite19.setPosition(skyPosition19);

	sf::Sprite SkySprite20;
	sf::Vector2f skyPosition20(0, -18000);
	SkySprite20.setTexture(BlueSky);
	SkySprite20.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite20.setPosition(skyPosition20);

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

	float xRotationVel = 0.9f;
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

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					skyPosition.y = -900;
					skyPosition2.y = -1800;
					skyPosition3.y = -2700;
					skyPosition4.y = -3600;
					skyPosition5.y = -4500;
					skyPosition6.y = -5400;
					skyPosition7.y = -6300;
					skyPosition8.y = -7200;
					skyPosition9.y = -8100;
					skyPosition10.y = -9000;
					skyPosition11.y = -9900;
					skyPosition12.y = -10800;
					skyPosition13.y = -11700;
					skyPosition14.y = -12600;
					skyPosition15.y = -13500;
					skyPosition16.y = -14400;
					skyPosition17.y = -15300;
					skyPosition18.y = -16200;
					skyPosition19.y = -17100;
					skyPosition20.y = -18000;
				}

				GameOn = true;
				break;
			}
		}

		//Start Screen
		if (GameOn == false) {

			window.draw(StartGameText);

			window.draw(KeyPressText);

			sf::Time elapsed = ScoreTimer.restart();
		}

		//GameOn Loop
		if (GameOn == true) {

			//Background Movement
			if (yBackgroundVel < 20) {
				yBackgroundVel += 0.1f;
			}

			mntnPosition.y += yBackgroundVel;
			mntnSprite.setPosition(mntnPosition);

			skyPosition.y += yBackgroundVel;
			SkySprite.setPosition(skyPosition);

			skyPosition2.y += yBackgroundVel;
			SkySprite2.setPosition(skyPosition2);

			skyPosition3.y += yBackgroundVel;
			SkySprite3.setPosition(skyPosition3);

			skyPosition4.y += yBackgroundVel;
			SkySprite4.setPosition(skyPosition4);

			skyPosition5.y += yBackgroundVel;
			SkySprite5.setPosition(skyPosition5);

			skyPosition6.y += yBackgroundVel;
			SkySprite6.setPosition(skyPosition6);

			skyPosition7.y += yBackgroundVel;
			SkySprite7.setPosition(skyPosition7);

			skyPosition8.y += yBackgroundVel;
			SkySprite8.setPosition(skyPosition8);

			skyPosition9.y += yBackgroundVel;
			SkySprite9.setPosition(skyPosition9);

			skyPosition10.y += yBackgroundVel;
			SkySprite10.setPosition(skyPosition10);

			skyPosition11.y += yBackgroundVel;
			SkySprite11.setPosition(skyPosition11);

			skyPosition12.y += yBackgroundVel;
			SkySprite12.setPosition(skyPosition12);

			skyPosition13.y += yBackgroundVel;
			SkySprite13.setPosition(skyPosition13);

			skyPosition14.y += yBackgroundVel;
			SkySprite14.setPosition(skyPosition14);

			skyPosition15.y += yBackgroundVel;
			SkySprite15.setPosition(skyPosition15);

			skyPosition16.y += yBackgroundVel;
			SkySprite16.setPosition(skyPosition16);

			skyPosition17.y += yBackgroundVel;
			SkySprite17.setPosition(skyPosition17);

			skyPosition18.y += yBackgroundVel;
			SkySprite18.setPosition(skyPosition18);

			skyPosition19.y += yBackgroundVel;
			SkySprite19.setPosition(skyPosition19);

			skyPosition20.y += yBackgroundVel;
			SkySprite20.setPosition(skyPosition20);


			window.draw(SkySprite);
			window.draw(SkySprite2);
			window.draw(SkySprite3);
			window.draw(SkySprite4);
			window.draw(SkySprite5);
			window.draw(SkySprite6);
			window.draw(SkySprite7);
			window.draw(SkySprite8);
			window.draw(SkySprite9);
			window.draw(SkySprite10);
			window.draw(SkySprite11);
			window.draw(SkySprite12);
			window.draw(SkySprite13);
			window.draw(SkySprite14);
			window.draw(SkySprite15);
			window.draw(SkySprite16);
			window.draw(SkySprite17);
			window.draw(SkySprite18);
			window.draw(SkySprite19);
			window.draw(SkySprite20);

			//Scoreboard
			sf::Time elapsed = ScoreTimer.getElapsedTime();

			score = elapsed.asSeconds() * 10;

			window.draw(Score);

			Score.setString(std::to_string(score));

			window.draw(ScoreText);

			window.draw(ResetText);
		}

		window.draw(RocketSprite);

		window.display();
	}
}