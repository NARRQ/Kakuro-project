#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>

//zawijanie tekstu
std::string wrapText(const std::string& text, sf::Font& font, unsigned int characterSize, float maxWidth);
//wczytanie fontu
sf::Font setFont();