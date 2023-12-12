#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>


std::string wrapText(const std::string& text, sf::Font& font, unsigned int characterSize, float maxWidth);
sf::Font setFont();