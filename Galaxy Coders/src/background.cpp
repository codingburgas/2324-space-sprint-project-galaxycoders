#include <iostream>
#include <SFML/Graphics.hpp>

void Textures(sf::RenderWindow& rWindow, float yBackgroundVel) {

	sf::Texture BlueSky;
	if (!BlueSky.loadFromFile("assets/background-1.png")) {
		std::cout << "Couldn't load sky background" << std::endl;
	}

	sf::Texture SkyTransition;
	if (!SkyTransition.loadFromFile("assets/background-2.png")) {
		std::cout << "Couldn't load sky background" << std::endl;
	}

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



	sf::Sprite TransitionSprite;
	sf::Vector2f transitionPosition(0, -8100);
	TransitionSprite.setTexture(SkyTransition);
	TransitionSprite.setScale(sf::Vector2f(1.65, 1.6));
	TransitionSprite.setPosition(transitionPosition);

	if (yBackgroundVel < 40) {
		yBackgroundVel += 0.1f;
	}

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

	transitionPosition.y += yBackgroundVel;
	TransitionSprite.setPosition(transitionPosition);

	rWindow.clear();
	rWindow.draw(SkySprite);
	rWindow.draw(SkySprite2);
	rWindow.draw(SkySprite3);
	rWindow.draw(SkySprite4);
	rWindow.draw(SkySprite5);
	rWindow.draw(SkySprite6);
	rWindow.draw(SkySprite7);
	rWindow.draw(SkySprite8);
	rWindow.draw(TransitionSprite);
	rWindow.display();
}