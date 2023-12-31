#include "PoleBlanc.h"
#include <SFML/Graphics.hpp>

void PoleBlanc::DrawPoleBlanc(sf::RenderWindow& window) const
{
	window.draw(shape);
	window.draw(poleblancText);
}
