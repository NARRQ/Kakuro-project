#include "Button.h"
#include <iostream>


void Button::draw(sf::RenderWindow& window) const {
    shape.setPosition(position);
    window.draw(shape);
    window.draw(buttonText);
}

bool Button::isMouseOver(const sf::RenderWindow& window) const {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool Button::isClicked(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        // Sprawdzanie, czy klikniêcie nast¹pi³o w obszarze przycisku
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::FloatRect buttonBounds = shape.getGlobalBounds();

        if (buttonBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            // Kolor zmieniany po klikniêciu
            shape.setFillColor(sf::Color(0,128,128));
        }
    }
    if (event.type == sf::Event::MouseButtonReleased) {
            // Powrót do pierwotnego koloru po puszczeniu przycisku myszy
            shape.setFillColor(sf::Color(0,240,240));
        }
    return isMouseOver(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void Button::setPosition(const sf::Vector2f& newPosition) {
    position = newPosition;
}

