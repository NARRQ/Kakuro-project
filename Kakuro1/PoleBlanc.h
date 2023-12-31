#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class PoleBlanc
{
private:
	sf::RectangleShape shape;
	sf::Text poleblancText{};
	sf::Glyph gl{};
	sf::Vector2f position;
public:
	//const sf::Vector2f size = sf::Vector2f(50,50);
	//konstruktor poleblanc
	PoleBlanc(sf::Vector2f possition, sf::Font& font,const std::string& number) : position(possition){
		//set shape

		shape.setPosition(position);
		shape.setSize(sf::Vector2f(50, 50));
		shape.setFillColor(sf::Color(0,240,240));

		//set number into shape
		poleblancText.setFont(font);	//ustawienie font
		poleblancText.setString(number);
		poleblancText.setCharacterSize(20);	//rozmiar
		poleblancText.setFillColor(sf::Color::Black);	//kolor czarny

		//center
		sf::FloatRect textBounds = poleblancText.getLocalBounds();
		poleblancText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
		poleblancText.setPosition(position.x + 40, position.y + 40);
		
		
	}
	void DrawPoleBlanc(sf::RenderWindow& window) const;
};

