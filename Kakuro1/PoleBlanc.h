#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class PoleBlanc
{
private:
	sf::RectangleShape shape;
	sf::Text poleblancText;
	sf::Vector2f position;
public:
	//const sf::Vector2f size = sf::Vector2f(50,50);
	//konstruktor poleblanc
	PoleBlanc(sf::Vector2f possition) : position(possition){
		//set shape

		shape.setPosition(position);
		shape.setSize(sf::Vector2f(50, 50));
		shape.setFillColor(sf::Color::Green);

		////set number into shape
		////center
		//sf::FloatRect textBounds = poleblancText.getLocalBounds();
		//poleblancText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
		//poleblancText.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
		//
		//sf::RectangleShape rectangle(sf::Vector2f(50, 50));
	}
	void DrawPoleBlanc(sf::RenderWindow& window);
};

