#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class PoleBlanc
{
private:
	sf::RectangleShape shape;
	sf::Text poleblancText_sumaWiersz{};
	sf::Text poleblancText_sumaKolumna{};
	sf::Glyph gl{};
	sf::Vector2f position;
public:
	//konstruktor poleblanc
	PoleBlanc(sf::Vector2f possition, sf::Font& font,const std::string& suma_kolumna, const std::string& suma_wiersz) : position(possition){
		//set shape
		shape.setPosition(position);
		shape.setSize(sf::Vector2f(50, 50));
		shape.setFillColor(sf::Color(0,240,240));
		
		//set numbers into shape
		//suma wiersz
		poleblancText_sumaWiersz.setFont(font);	//ustawienie font
		poleblancText_sumaWiersz.setString(suma_wiersz);
		poleblancText_sumaWiersz.setCharacterSize(20);	//rozmiar
		poleblancText_sumaWiersz.setFillColor(sf::Color::Black);	//kolor czarny
		//pozycja dla suma wiersz
		sf::FloatRect textBounds_wiersz = poleblancText_sumaWiersz.getLocalBounds();
		poleblancText_sumaWiersz.setOrigin(textBounds_wiersz.left + textBounds_wiersz.width / 2.0f, textBounds_wiersz.top + textBounds_wiersz.height / 2.0f);
		poleblancText_sumaWiersz.setPosition(position.x + 40, position.y + 10);
		
		//suma kolumna
		poleblancText_sumaKolumna.setFont(font);	//ustawienie font
		poleblancText_sumaKolumna.setString(suma_kolumna);
		poleblancText_sumaKolumna.setCharacterSize(20);	//rozmiar
		poleblancText_sumaKolumna.setFillColor(sf::Color::Black);	//kolor czarny
		//pozycja dla suma kolumn
		sf::FloatRect textBounds_kolumna = poleblancText_sumaKolumna.getLocalBounds();
		poleblancText_sumaKolumna.setOrigin(textBounds_kolumna.left + textBounds_kolumna.width / 2.0f, textBounds_kolumna.top + textBounds_kolumna.height / 2.0f);
		poleblancText_sumaKolumna.setPosition(position.x + 10, position.y + 40);
	}
	~PoleBlanc(){}
	void DrawPoleBlanc(sf::RenderWindow& window) const;
};

