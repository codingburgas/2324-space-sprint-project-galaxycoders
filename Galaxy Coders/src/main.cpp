#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


int main() {

	const int windowWidth = 1600;
	const int windowHeight = 900;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Galaxy Coders");
	window.setFramerateLimit(60);

	bool GameOn = false;
	bool GameOver = false;


	//GAME TEXT
	sf::Text StartGameText;
	sf::Text KeyPressText;
	sf::Text Score;
	sf::Text ScoreText;
	sf::Text ResetText;
	sf::Text DyingText;
	sf::Text DyingResetText;
	sf::Text Info1;
	sf::Text Info2;
	sf::Text Info3;
	sf::Text Info4;
	sf::Text Info5;
	sf::Text Info6;
	sf::Text Info7;
	sf::Text Info8;
	sf::Text Info9;
	sf::Text Info10;

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


	//GameOver Text
	sf::Texture TextBox;
	if (!TextBox.loadFromFile("assets/textbox.png")) {
		std::cout << "Couldn't load text box" << std::endl;
	}

	sf::Sprite TextBoxSprite;
	sf::Vector2f TextBoxPos(200, -100);

	TextBoxSprite.setTexture(TextBox);
	TextBoxSprite.setPosition(TextBoxPos);
	TextBoxSprite.setScale(sf::Vector2f(6, 6));

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

	Info1.setString("The Higgs boson is an elementary particle predicted\n in the standard model of particle physics.");
	Info1.setFont(KGCPFont);
	Info1.setPosition(sf::Vector2f(360, 390));
	Info1.setCharacterSize(35);
	Info1.setFillColor(sf::Color::Black);

	Info2.setString("The Higgs boson's existence was predicted in 1964 by \nPeter Higgs, Francois Englert, Robert Brout, and \nother scientists.");
	Info2.setFont(KGCPFont);
	Info2.setPosition(sf::Vector2f(360, 390));
	Info2.setCharacterSize(35);
	Info2.setFillColor(sf::Color::Black);

	Info3.setString("The Higgs boson was discovered in experiments at \nthe Large Hadron Collider in 2012.");
	Info3.setFont(KGCPFont);
	Info3.setPosition(sf::Vector2f(360, 390));
	Info3.setCharacterSize(35);
	Info3.setFillColor(sf::Color::Black);

	Info4.setString("The Higgs boson is also known as the God particle \ndue to its crucial role in the structure of the \nUniverse.");
	Info4.setFont(KGCPFont);
	Info4.setPosition(sf::Vector2f(380, 390));
	Info4.setCharacterSize(35);
	Info4.setFillColor(sf::Color::Black);

	Info5.setString("The mass of the Higgs boson is about 125 \ngigaelectronvolts, with a spin of 0 and an \nelectric charge of 0.");
	Info5.setFont(KGCPFont);
	Info5.setPosition(sf::Vector2f(450, 390));
	Info5.setCharacterSize(35);
	Info5.setFillColor(sf::Color::Black);

	Info6.setString("The Higgs boson plays a crucial role in the \nmechanism of assigning mass to other particles, \nincluding hadrons and leptons.");
	Info6.setFont(KGCPFont);
	Info6.setPosition(sf::Vector2f(380, 390));
	Info6.setCharacterSize(35);
	Info6.setFillColor(sf::Color::Black);

	Info7.setString("The Higgs boson is part of the quantum field \nknown as the Higgs field, which fills the entire \nUniverse.");
	Info7.setFont(KGCPFont);
	Info7.setPosition(sf::Vector2f(380, 390));
	Info7.setCharacterSize(37);
	Info7.setFillColor(sf::Color::Black);

	Info8.setString("The Higgs boson can decay into other particles, \nallowing scientists to study its properties and \ninteractions.");
	Info8.setFont(KGCPFont);
	Info8.setPosition(sf::Vector2f(390, 390));
	Info8.setCharacterSize(35);
	Info8.setFillColor(sf::Color::Black);

	Info9.setString("The discovery of the Higgs boson helps us better \nunderstand the origin of the Universe and its early \nstages of development.");
	Info9.setFont(KGCPFont);
	Info9.setPosition(sf::Vector2f(360, 390));
	Info9.setCharacterSize(35);
	Info9.setFillColor(sf::Color::Black);

	Info10.setString("Understanding the Higgs boson opens up new perspectives for \nscientific research and technological developments, including \nthe creation of new methods for disease treatment and the \n                        development of new materials.");
	Info10.setFont(KGCPFont);
	Info10.setPosition(sf::Vector2f(360, 390));
	Info10.setCharacterSize(29);
	Info10.setFillColor(sf::Color::Black);


	//BACKGROUND TEXTURES
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
	sf::Vector2f M1Position(230, -150);

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
	float yRocketVelocity = 12;

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


		//Start Screen
		if (GameOn == false && GameOver == false) {
			window.draw(StartGameText);
			window.draw(KeyPressText);
			sf::Time elapsed = ScoreTimer.restart();
			window.draw(RocketSprite);
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

			//Scoreboard
			sf::Time elapsed = ScoreTimer.getElapsedTime();
			score = elapsed.asSeconds() * 10;

			window.draw(Score);
			Score.setString(std::to_string(score));
			window.draw(ScoreText);
			window.draw(ResetText);
			window.draw(RocketSprite2);
		}

		if (GameOver == true) {
			window.draw(TextBoxSprite);
			window.draw(DyingText);
			window.draw(DyingResetText);

			if (score > 10 && score < 200) {
				window.draw(Info1);
			}

			if (score > 200 && score < 450) {
				window.draw(Info2);
			}

			if (score > 450 && score < 850) {
				window.draw(Info3);
			}

			if (score > 850 && score < 1250) {
				window.draw(Info4);
			}

			if (score > 1250 && score < 1600) {
				window.draw(Info5);
			}

			if (score > 1600 && score < 1950) {
				window.draw(Info6);
			}

			if (score > 1950 && score < 2300) {
				window.draw(Info7);
			}

			if (score > 2300 && score < 2700) {
				window.draw(Info8);
			}

			if (score > 2700 && score < 3100) {
				window.draw(Info9);
			}

			if (score > 3100) {
				window.draw(Info10);
			}
		}

		window.display();
	}
}