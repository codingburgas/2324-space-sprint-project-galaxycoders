#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <string>

#include "main.h"
const int windowWidth = 1600;
const int windowHeight = 900;



void deathText(sf::RenderWindow &rWindow, sf::Clock &ScoreTimer) {

	sf::Time elapsed = ScoreTimer.getElapsedTime();
	int score;
	score = elapsed.asSeconds() * 10;

	sf::Text DyingText;
	sf::Text DyingResetText;
	sf::Text deathInfo[10];
	sf::Sprite TextBoxSprite;

	gameOver(deathInfo[10], TextBoxSprite);
	rWindow.draw(TextBoxSprite);
	rWindow.draw(DyingText);
	rWindow.draw(DyingResetText);

	if (score > 10 && score < 200) {
		rWindow.draw(deathInfo[0]);
	}

	if (score > 200 && score < 450) {
		rWindow.draw(deathInfo[1]);
	}

	if (score > 450 && score < 850) {
		rWindow.draw(deathInfo[2]);
	}
	
	if (score > 850 && score < 1250) {
		rWindow.draw(deathInfo[3]);
	}

	if (score > 1250 && score < 1600) {
		rWindow.draw(deathInfo[4]);
	}

	if (score > 1600 && score < 1950) {
		rWindow.draw(deathInfo[5]);
	}

	if (score > 1950 && score < 2300) {
		rWindow.draw(deathInfo[6]);
	}

	if (score > 2300 && score < 2700) {
		rWindow.draw(deathInfo[7]);
	}

	if (score > 2700 && score < 3100) {
		rWindow.draw(deathInfo[8]);
	}

	if (score > 3100) {
		rWindow.draw(deathInfo[9]);
	}

}


void skyTextures(sf::Sprite& SkySprite, sf::Sprite& SkySprite2, sf::Vector2f& skyPosition, sf::Vector2f& skyPosition2) {

	sf::Texture SkyBackground;
	if (!SkyBackground.loadFromFile("assets/background-1.png")) {
		std::cout << "Couldn't load sky background" << std::endl;
	}

	//Sky Background
	SkySprite.setTexture(SkyBackground);
	SkySprite.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite.setPosition(skyPosition);

	SkySprite2.setTexture(SkyBackground);
	SkySprite2.setScale(sf::Vector2f(1.65, 1.6));
	SkySprite2.setPosition(skyPosition2);

}


void transitionTexture(sf::Sprite &TransitionSprite, sf::Vector2f &transitionPosition) {
	sf::Texture TransitionBackground;
	if (!TransitionBackground.loadFromFile("assets/background-2.png")) {
		std::cout << "Couldn't load transition background" << std::endl;
	}

	//Transition Background
	TransitionSprite.setTexture(TransitionBackground);
	TransitionSprite.setScale(sf::Vector2f(1.65, 1.525));
	TransitionSprite.setPosition(transitionPosition);
}


void spaceTextures(sf::Sprite &SpaceSprite, sf::Sprite &SpaceSprite2, sf::Vector2f &spacePosition, sf::Vector2f &spacePosition2) {

	sf::Texture SpaceBackground;
	if (!SpaceBackground.loadFromFile("assets/background-3.png")) {
		std::cout << "Couldn't load space background" << std::endl;
	}

	//Space Background
	SpaceSprite.setTexture(SpaceBackground);
	SpaceSprite.setScale(sf::Vector2f(1.65, 1.6));
	SpaceSprite.setPosition(spacePosition);

	SpaceSprite2.setTexture(SpaceBackground);
	SpaceSprite2.setScale(sf::Vector2f(1.65, 1.6));
	SpaceSprite2.setPosition(spacePosition2);
}


void mountainTextures(sf::Sprite &mntnSprite, sf::Vector2f &mntnPosition) {
	sf::Texture mntnBackground;
	if (!mntnBackground.loadFromFile("assets/45908.jpg")) {
		std::cout << "Couldn't load mountain background" << std::endl;
	}

	mntnSprite.setTexture(mntnBackground);
	mntnSprite.setScale(sf::Vector2f(0.22, 0.2));
	mntnSprite.setPosition(mntnPosition);
}


void meteoriteTextures(sf::Sprite &M1Sprite, sf::Vector2f &M1Position) {
	sf::Texture Meteorite1;
	if (!Meteorite1.loadFromFile("assets/meteorite1-0-1.png")) {
		std::cout << "Couldn't load meteorite 1" << std::endl;
	}

	M1Sprite.setTexture(Meteorite1);
	M1Sprite.setPosition(M1Position);
	M1Sprite.setOrigin(sf::Vector2f( 75, 70));
}


void rocketTextures(sf::Sprite& RocketSprite, sf::Sprite &RocketSprite2, sf::Vector2f &RocketPosition2) {
	sf::Texture Rocket;
	if (!Rocket.loadFromFile("assets/Spaceship.png")) {
		std::cout << "Couldn't load rocket" << std::endl;
	}

	
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

	RocketSprite2.setTexture(Rocket2);
	RocketSprite2.setPosition(RocketPosition2);
	RocketSprite2.setScale(sf::Vector2f(1, 1));
	RocketSprite2.setOrigin(sf::Vector2f(100, 0));
}


int main() {
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaxy Coders");
	window.setFramerateLimit(60);

	bool GameOn = false;
	bool GameOver = false;

	sf::Clock ScoreTimer;

	//Start Screen Text
	sf::Text StartGameText;
	sf::Text KeyPressText;
	int score = 0;
	startScreenText(StartGameText, KeyPressText);
	

	//GameOn Text
	gameOnText();


	//GameOver Text
	sf::Text deathInfo[10];
	sf::Sprite TextBoxSprite;
	gameOver(deathInfo[10], TextBoxSprite);

	
	//BACKGROUND TEXTURES
	float yBackgroundVel = 2;
	int SkySpriteLayers = 0;

	sf::Sprite SkySprite;
	sf::Sprite SkySprite2;
	sf::Vector2f skyPosition(0, -900);
	sf::Vector2f skyPosition2(0, -1800);
	skyTextures(SkySprite, SkySprite2, skyPosition, skyPosition2);


	sf::Sprite TransitionSprite;
	sf::Vector2f transitionPosition(0, -900);
	transitionTexture(TransitionSprite, transitionPosition);


	sf::Sprite SpaceSprite;
	sf::Sprite SpaceSprite2;
	sf::Vector2f spacePosition(0, -900);
	sf::Vector2f spacePosition2(0, -1800);
	spaceTextures(SpaceSprite, SpaceSprite2, spacePosition, spacePosition2);


	sf::Sprite mntnSprite;
	sf::Vector2f mntnPosition(-70, 0);
	mountainTextures(mntnSprite, mntnPosition);


	//Meteorite Textures
	sf::Sprite M1Sprite;
	sf::Vector2f M1Position(230, -140);
	meteoriteTextures(M1Sprite, M1Position);
	float MeteoriteVel = 10;
	int MeteoriteAngleVel = 0;



	//ROCKET TEXTURES
	sf::Sprite RocketSprite;
	sf::Sprite RocketSprite2;
	sf::Vector2f RocketPosition2(810, 550);
	rocketTextures(RocketSprite, RocketSprite2, RocketPosition2);

	float xRocketVelocity = 10;
	float yRocketVelocity = 12;
	


	//GAME LOOP
	while (window.isOpen()) {


		//Rocket Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			RocketPosition2.x -= xRocketVelocity;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			RocketPosition2.x += xRocketVelocity;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (RocketPosition2.y > 0) {
				RocketPosition2.y -= yRocketVelocity;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (RocketPosition2.y < 700) {
				RocketPosition2.y += yRocketVelocity;
			}
		}
		RocketSprite2.setPosition(RocketPosition2);



		//Walls Collision Physics
		if (RocketPosition2.x > 1600) {
			RocketPosition2.x = -90;
		}

		else if (RocketPosition2.x < -100) {
			RocketPosition2.x = 1600;
		}


		RocketSprite2.setPosition(RocketPosition2);



		//Meteorite Collision Physics
		if (M1Position.x >= (RocketPosition2.x - 80) && M1Position.x <= (RocketPosition2.x + 80)) {
			if (M1Position.y >= RocketPosition2.y && M1Position.y <= (RocketPosition2.y + 200)) {
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
						mntnPosition.y = 0;
						mntnSprite.setPosition(mntnPosition);
						RocketPosition2.x = 810;
						RocketPosition2.y = 550;
						skyPosition.y = -900;
						skyPosition2.y = -1800;
						spacePosition.y = -900;
						SpaceSprite.setPosition(spacePosition);
						spacePosition2.y = -1800;
						SpaceSprite2.setPosition(spacePosition2);
						SkySpriteLayers = 0;
						yBackgroundVel = 2;
						transitionPosition.y = -900;
						TransitionSprite.setPosition(transitionPosition);
						M1Position.y = -140;
						M1Sprite.setPosition(M1Position);
					}

					else {
					GameOn = true;
					}
				}

				if (GameOver == true) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						GameOver = false;
						GameOn = false;
						mntnPosition.y = 0;
						mntnSprite.setPosition(mntnPosition);
						RocketPosition2.x = 810;
						RocketPosition2.y = 550;
						skyPosition.y = -900;
						skyPosition2.y = -1800;
						spacePosition.y = -900;
						SpaceSprite.setPosition(spacePosition);
						spacePosition2.y = -1800;
						SpaceSprite2.setPosition(spacePosition2);
						SkySpriteLayers = 0;
						yBackgroundVel = 2;
						transitionPosition.y = -900;
						TransitionSprite.setPosition(transitionPosition);
						M1Position.y = -140;
						M1Sprite.setPosition(M1Position);
					}
				}

				break;
			}
		}



		



		//GameOn Loop
		if (GameOn == true) {



			//BACKGROUND MOVEMENT
			if (yBackgroundVel < 15) {
				yBackgroundVel += 0.1f;
			}

			mntnPosition.y += yBackgroundVel;
			mntnSprite.setPosition(mntnPosition);

			//Background Loops
			if (SkySpriteLayers <= 50) {
				
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
			if (SkySpriteLayers >= 52 && SkySpriteLayers < 54) {
				
				transitionPosition.y += yBackgroundVel;
				TransitionSprite.setPosition(transitionPosition);
				window.draw(TransitionSprite);
				
				if (transitionPosition.y >= 900) {
					SkySpriteLayers += 2;
				}
			}

			if (SkySpriteLayers >= 52) {

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
						MeteoriteAngleVel += 5;
					}
				}
				else {
					int MeteoriteAngle = (rand() % 8) - 16;
					MeteoriteAngleVel = MeteoriteAngle;
					if (MeteoriteAngleVel >= -2) {
						MeteoriteAngleVel -= 5;
					}
				}
			}

			//Meteorite Movement
			if (SkySpriteLayers >= 2) {
				M1Position.y += 20.0f;
				M1Position.x += MeteoriteAngleVel;
	
				M1Sprite.setPosition(M1Position);
				window.draw(M1Sprite);

				if (M1Position.y >= 890) {
					M1Position.y = -130;
					M1Sprite.setPosition(M1Position);
					window.draw(SkySprite2);
				}
			}



		}
		


		if (GameOver == true) {

			deathText(window, ScoreTimer);
		}

		window.display();
	}
}