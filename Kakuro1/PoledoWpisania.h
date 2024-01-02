#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class PoledoWpisania
{
public:
    PoledoWpisania(sf::Vector2f position, sf::Font& font)
        : rectangle(sf::Vector2f(50, 50)), isTextInputActive(false),position(position) {
        rectangle.setPosition(position);
        rectangle.setFillColor(sf::Color(240, 240, 240));


        text.setFont(font);
        text.setCharacterSize(20);
        text.setPosition(position.x + 20, position.y + 10);
        text.setFillColor(sf::Color::Black);
    }

    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;
    int getValue() const;
    void setvalue(int value);

private:
    sf::RectangleShape rectangle;
    sf::Vector2f position;
    sf::Text text{};
    bool isTextInputActive{};
    std::string inputText{};
};

