#include "PoledoWpisania.h"

void PoledoWpisania::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::MouseButtonPressed) 
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (rectangle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) 
        {
            isTextInputActive = true;
            rectangle.setFillColor(sf::Color::Yellow);
        }
        else 
        {
            isTextInputActive = false;
            rectangle.setFillColor(sf::Color(240, 240, 240));
        }
    }
    else if (event.type == sf::Event::TextEntered) 
    {
        if (isTextInputActive) 
        {
            if (event.text.unicode == 8 && !inputText.empty()) 
            {
                // Backspace: usuñ ostatni znak
                inputText.pop_back();
            }
            else if (event.text.unicode > 48 && event.text.unicode < 58 && inputText.length() < 1) 
            {
                // Dodaj wprowadzony znak do tekstu
                inputText += static_cast<char>(event.text.unicode);
            }

            text.setString(inputText);
        }
    }
}

void PoledoWpisania::draw(sf::RenderWindow& window) const
{
	window.draw(rectangle);
	window.draw(text);
}

int PoledoWpisania::getValue() const
{
    if (inputText.empty())
    {
        return 0;
    }
    return std::stoi(inputText);
}

void PoledoWpisania::setvalue(int value)
{
    //int na string
    inputText = std::to_string(value);
    text.setString(inputText);
    text.setFillColor(sf::Color(0, 128, 0));
}

int PoledoWpisania::getIdK() const
{
    return id_k;
}

int PoledoWpisania::getIdW() const
{
    return id_w;
}
