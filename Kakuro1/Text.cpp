#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Text.hpp"

std::string wrapText(const std::string& text, sf::Font& font, unsigned int characterSize, float maxWidth) {
    std::stringstream wrappedText;
    std::stringstream lineStream(text);
    std::string word;
    float lineWidth = 0.0f;

    while (lineStream >> word) {
        sf::Text tempText(word, font, characterSize);
        float wordWidth = tempText.getLocalBounds().width;

        if (lineWidth + wordWidth > maxWidth) {
            wrappedText << '\n';
            lineWidth = 0.0f;
        }

        wrappedText << word << ' ';
        lineWidth += wordWidth;
    }

    return wrappedText.str();
}
sf::Font setFont()
{
    sf::Font font;
    if (!font.loadFromFile("AbhayaLibre-Bold.ttf")) {
        std::cerr << "Error loading font\n";
        //return -1;
    }
    return font;
}