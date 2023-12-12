#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class PoledoWpisania
{

private:
	sf::RectangleShape shape;
	sf::Text poleblancText;
	sf::Vector2f position;
public:
	//const sf::Vector2f size = sf::Vector2f(50,50);
	//konstruktor poleblanc
	PoledoWpisania(sf::Vector2f possition) : position(possition) {
		//set shape

		shape.setPosition(position);
		shape.setSize(sf::Vector2f(50, 50));
		shape.setFillColor(sf::Color::White);
	}
	void DrawPoledoWpisania(sf::RenderWindow& window);
};

