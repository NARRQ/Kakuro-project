#include "Button.h"
#include <iostream>


void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(buttonText);
}

bool Button::isMouseOver(const sf::RenderWindow& window) const {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool Button::isClicked(const sf::RenderWindow& window) const {
    return isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

    // You can add more functionality as needed, such as changing the button appearance on hover, etc.
