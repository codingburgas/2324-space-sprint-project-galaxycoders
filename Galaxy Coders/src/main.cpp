#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <string>

int main() {
	const int windowWidth = 1600;
	const int windowHeight = 900;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaxy Coders");
	window.setFramerateLimit(60);

	bool GameOn = false;
	bool GameOver = false;



	//Game Text
	sf::Text StartGameText;
	sf::Text KeyPressText;
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





	//Background Textures
	sf::Texture mntnBackground;
	if (!mntnBackground.loadFromFile("assets/45908.jpg")) {
		std::cout << "Couldn't load mountain background" << std::endl;
	}

	sf::Texture SkyBackground;
	if (!SkyBackground.loadFromFile("assets/background-1.png")) {
		std::cout << "Couldn't load sky background" << std::endl;
	}

	sf::Texture TransitionBackground;
	if (!TransitionBackground.loadFromFile("assets/background-2.png")) {
		std::cout << "Couldn't load transition background" << std::endl;
	}

	sf::Texture SpaceBackground;
	if (!SpaceBackground.loadFromFile("assets/background-3.png")) {
		std::cout << "Couldn't load space background" << std::endl;
	}

	sf::Sprite mntnSprite;
	sf::Vector2f mntnPosition(-70, 0);
	mntnSprite.setTexture(mntnBackground);
	mntnSprite.setScale(sf::Vector2f(0.22, 0.2));
	mntnSprite.setPosition(mntnPosition);

	//Sky Background
	sf::Sprite SkySprite;
	sf::Vector2f skyPosition(0, -900);
	SkySprite.setTexture(SkyBackground);
	SkySprite.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite.setPosition(skyPosition);

	sf::Sprite SkySprite2;
	sf::Vector2f skyPosition2(0, -1800);
	SkySprite2.setTexture(SkyBackground);
	SkySprite2.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite2.setPosition(skyPosition2);

	//Transition Background
	sf::Sprite TransitionSprite;
	sf::Vector2f transitionPosition(0, -900);
	TransitionSprite.setTexture(TransitionBackground);
	TransitionSprite.setScale(sf::Vector2f(1.65, 1.525));
	TransitionSprite.setPosition(transitionPosition);

	//Space Background
	sf::Sprite SpaceSprite;
	sf::Vector2f spacePosition(0, -900);
	SpaceSprite.setTexture(SpaceBackground);
	SpaceSprite.setScale(sf::Vector2f(1.65, 1.6));
	SpaceSprite.setPosition(spacePosition);

	sf::Sprite SpaceSprite2;
	sf::Vector2f spacePosition2(0, -1800);
	SpaceSprite2.setTexture(SpaceBackground);
	SpaceSprite2.setScale(sf::Vector2f(1.65, 1.6));
	SpaceSprite2.setPosition(spacePosition2);

	float yBackgroundVel = 2;
	int SkySpriteLayers = 0;




	//Meteorite Textures
	sf::Texture Meteorite1;
	if (!Meteorite1.loadFromFile("assets/meteorite1-0-1.png")) {
		std::cout << "Couldn't load meteorite 1" << std::endl;
	}

	sf::Sprite M1Sprite;
	sf::Vector2f M1Position(230, -140);
	M1Sprite.setTexture(Meteorite1);
	M1Sprite.setPosition(M1Position);
	M1Sprite.setOrigin(sf::Vector2f(75, 70));
	float MeteoriteVel = 10;
	int MeteoriteAngleVel = 0;



	//ROCKET TEXTURES
	
	//First Rocket
	sf::Texture Rocket;
	if (!Rocket.loadFromFile("assets/Spaceship.png")) {
		std::cout << "Couldn't load rocket" << std::endl;
	}

	sf::Sprite RocketSprite;
	sf::Vector2f RocketPosition(810, 550);

	RocketSprite.setTexture(Rocket);
	RocketSprite.setPosition(RocketPosition);
	RocketSprite.setScale(sf::Vector2f(1, 1));
	RocketSprite.setOrigin(sf::Vector2f(100, 0));

	//Second Rocket 
	sf::Texture Rocket2;
	if (!Rocket2.loadFromFile("assets/Spaceship-1.png")) {
		std::cout << "Couldn't load rocket" << std::endl;
	}

	sf::Sprite RocketSprite2;
	sf::Vector2f RocketPosition2(810, 550);

	RocketSprite2.setTexture(Rocket2);
	RocketSprite2.setPosition(RocketPosition2);
	RocketSprite2.setScale(sf::Vector2f(1, 1));
	RocketSprite2.setOrigin(sf::Vector2f(100, 0));

	float xRocketVelocity = 10;
	 

	sf::Clock ScoreTimer;



	//GAME LOOP
	while (window.isOpen()) {


		//Rocket Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			RocketPosition2.x -= xRocketVelocity;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			RocketPosition2.x += xRocketVelocity;
			
		}
		RocketSprite2.setPosition(RocketPosition2);



		//Walls Collision Physics
		if (RocketPosition2.x > 1840) {
			RocketPosition2.x = -10;
		}

		else if (RocketPosition2.x < -10) {
			RocketPosition2.x = 1840;
		}

		else if (RocketPosition2.x > 1840) {
			RocketPosition2.x = -10;
		}

		else if (RocketPosition2.x < -10) {
			RocketPosition2.x = 1840;
		}

		RocketSprite2.setPosition(RocketPosition2);



		//Meteorite Collision Physics
		if (M1Position.x >= (RocketPosition2.x - 50) && M1Position.x <= (RocketPosition2.x + 50)) {
			if (M1Position.y >= RocketPosition2.y && M1Position.y <= (RocketPosition2.y + 100)) {
				GameOver = true;
				GameOn = false;
			}
		}



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

				//Reset Button
				if (GameOver == false) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
						GameOn = false;
						GameOver = false;
						mntnPosition.y = 0;
						mntnSprite.setPosition(mntnPosition);
						RocketPosition.x = 810;
						skyPosition.y = -900;
						skyPosition2.y = -1800;
						spacePosition.y = -900;
						spacePosition2.y = -1800;
						SkySpriteLayers = 0;
						yBackgroundVel = 2;
						transitionPosition.y = -900;
					}

					else {
					GameOn = true;
					}
				
				}

				break;
			}
		}



		//Start Screen
		if (GameOn == false && GameOver == false) {

			window.draw(StartGameText);

			window.draw(KeyPressText);

			sf::Time elapsed = ScoreTimer.restart();

			window.draw(RocketSprite);

		}



		//GameOn Loop
		if (GameOn == true) {



			//Background Movement
			if (yBackgroundVel < 15) {
				yBackgroundVel += 0.1f;
			}

			mntnPosition.y += yBackgroundVel;
			mntnSprite.setPosition(mntnPosition);

			//Background Loop
			if (SkySpriteLayers <= 10) {
				
				if (skyPosition.y >= 890) {
					skyPosition.y = -900;
					SkySprite.setPosition(skyPosition);
					window.draw(SkySprite);
				}

				if (skyPosition2.y >= 900) {
					skyPosition2.y = -900;
					SkySprite2.setPosition(skyPosition2);
					window.draw(SkySprite2);
					SkySpriteLayers += 2;
				}
			}
			if (SkySpriteLayers >= 12 && SkySpriteLayers < 14) {
				
				transitionPosition.y += yBackgroundVel;
				TransitionSprite.setPosition(transitionPosition);
				window.draw(TransitionSprite);
				
				if (transitionPosition.y >= 900) {
					SkySpriteLayers += 2;
				}
			}

			if (SkySpriteLayers >= 12) {

				if (spacePosition.y >= 890) {
					spacePosition.y = -900;
					SpaceSprite.setPosition(spacePosition);
					window.draw(SpaceSprite);
				}

				if (spacePosition2.y >= 890) {
					spacePosition2.y = -900;
					SpaceSprite2.setPosition(spacePosition2);
					window.draw(SpaceSprite2);
					SkySpriteLayers += 2;
				}
			spacePosition.y += yBackgroundVel;
			SpaceSprite.setPosition(spacePosition);

			spacePosition2.y += yBackgroundVel;
			SpaceSprite2.setPosition(spacePosition2);

			}

			skyPosition.y += yBackgroundVel;
			SkySprite.setPosition(skyPosition);

			skyPosition2.y += yBackgroundVel;
			SkySprite2.setPosition(skyPosition2);
			
			window.draw(SpaceSprite);
			window.draw(SpaceSprite2);
			window.draw(SkySprite);
			window.draw(SkySprite2);
			window.draw(TransitionSprite);



			//METEORITE PHYSICS
			 
			//Random Meteorite Position
			if (M1Position.y == -130) {
				M1Position.x = (rand() % 1450) + 1;
				M1Sprite.setPosition(M1Position);

				//Random Meteorite Angle
				if (M1Position.x < 800) {
					int MeteoriteAngle = (rand() % 8);
					MeteoriteAngleVel = MeteoriteAngle;
					if (MeteoriteAngleVel <= 2) {
						MeteoriteAngleVel += 3;
					}
				}
				else {
					int MeteoriteAngle = (rand() % 8) - 16;
					MeteoriteAngleVel = MeteoriteAngle;
					if (MeteoriteAngleVel >= -2) {
						MeteoriteAngleVel -= 3;
					}
				}
			}

			//Meteorite Movement
			if (SkySpriteLayers >= 2) {
				M1Position.y += 10.0f;
				M1Position.x += MeteoriteAngleVel;
	
				M1Sprite.setPosition(M1Position);
				window.draw(M1Sprite);

				if (M1Position.y >= 890) {
					M1Position.y = -150;
					M1Sprite.setPosition(M1Position);
					window.draw(SkySprite2);
				}
			}



			//Scoreboard
			sf::Time elapsed = ScoreTimer.getElapsedTime();

			score = elapsed.asSeconds() * 10;

			window.draw(Score);

			Score.setString(std::to_string(score));

			window.draw(ScoreText);

			window.draw(ResetText);

			window.draw(RocketSprite2);
		}



		window.display();
	}
}