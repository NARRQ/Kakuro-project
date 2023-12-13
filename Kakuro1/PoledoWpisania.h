#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class PoledoWpisania
{

private:
	sf::RectangleShape shape;
	sf::Vector2f position;
	sf::Text poledowpisaniaText;
	
	//std::string userInput;
public:
	//const sf::Vector2f size = sf::Vector2f(50,50);
	//konstruktor poleblanc
	PoledoWpisania(sf::Vector2f possition, sf::Font& font) : position(possition) {
		
		//set shape
		shape.setPosition(position);
		shape.setSize(sf::Vector2f(50, 50));
		shape.setFillColor(sf::Color::White);

		//set text
		poledowpisaniaText.setFont(font);	//ustawienie font
		poledowpisaniaText.setString("0");
		poledowpisaniaText.setCharacterSize(20);	//rozmiar
		poledowpisaniaText.setFillColor(sf::Color::Black);	//kolor czarny


		// Center text within the button
		sf::FloatRect textBounds = poledowpisaniaText.getLocalBounds();
		poledowpisaniaText.setOrigin(textBounds.left + textBounds.width / 2.0f,
			textBounds.top + textBounds.height / 2.0f);
		poledowpisaniaText.setPosition(position.x + 50 / 2.0f, position.y + 50 / 2.0f);

	}
	void DrawPoledoWpisania(sf::RenderWindow& window);

};

