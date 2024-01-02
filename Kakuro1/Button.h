#pragma once
#include<SFML/Graphics.hpp>
class Button
{
private:
    sf::RectangleShape shape;
    sf::Text buttonText{};
    sf::Vector2f position;
    sf::Vector2f size;
public:
    //konstruct button
    Button(sf::Vector2f position, sf::Vector2f size, sf::Font& font, const std::string& text)
        : position(position), size(size) {
        shape.setPosition(position);
        shape.setSize(size);
        shape.setFillColor(sf::Color(0,240,240));
       
        buttonText.setFont(font);
        buttonText.setString(text);
        buttonText.setCharacterSize(20);
        buttonText.setFillColor(sf::Color::Black);

        // Center text within the button
        sf::FloatRect textBounds = buttonText.getLocalBounds();
        buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f,textBounds.top + textBounds.height / 2.0f);
        buttonText.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
    }
    void draw(sf::RenderWindow& window) const;
    bool isMouseOver(const sf::RenderWindow& window) const;
    bool isClicked(const sf::Event& event, const sf::RenderWindow& window);

};

