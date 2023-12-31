#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class PoledoWpisania
{
public:
    PoledoWpisania(sf::Vector2f position, sf::Font& font)
        : rectangle(sf::Vector2f(50, 50)), isTextInputActive(false),position(position) {
        rectangle.setPosition(position);
        rectangle.setFillColor(sf::Color::White);


        text.setFont(font);
        text.setCharacterSize(20);
        text.setPosition(position.x + 20, position.y + 10);
        text.setFillColor(sf::Color::Black);
    }

    void handleEvent(const sf::Event& event, sf::RenderWindow& window);

    void draw(sf::RenderWindow& window) const;

private:
    sf::RectangleShape rectangle;
    sf::Vector2f position;
    sf::Text text;
    //sf::Font font;
    bool isTextInputActive;
    std::string inputText;
};

