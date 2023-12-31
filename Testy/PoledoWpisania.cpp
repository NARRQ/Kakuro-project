#include "PoledoWpisania.h"

void PoledoWpisania::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (rectangle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                isTextInputActive = true;
                rectangle.setFillColor(sf::Color::Yellow);
            }
            else {
                isTextInputActive = false;
                rectangle.setFillColor(sf::Color::White);
            }
        }
        else if (event.type == sf::Event::TextEntered) {
            if (isTextInputActive) {
                if (event.text.unicode == 8 && !inputText.empty()) {
                    // Backspace: usuñ ostatni znak
                    inputText.pop_back();
                }
                else if (event.text.unicode >48 && event.text.unicode < 58 && inputText.length()<1) {
                    // Dodaj wprowadzony znak do tekstu
                    inputText += static_cast<char>(event.text.unicode);
                }

                text.setString(inputText);
            }
        }
    }
}

void PoledoWpisania::draw(sf::RenderWindow& window) const
{
	window.draw(rectangle);
	window.draw(text);
}
