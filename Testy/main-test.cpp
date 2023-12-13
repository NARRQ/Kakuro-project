#include <SFML/Graphics.hpp>
#include <iostream>

class TextInput {
public:
    TextInput(sf::RenderWindow& window, const sf::Font& font, unsigned int characterSize, const sf::Color& textColor, const sf::Vector2f& inputPosition, const sf::Vector2f& outputPosition)
        : window(window), font(font), characterSize(characterSize), textColor(textColor), inputPosition(inputPosition), outputPosition(outputPosition) {
        text.setFont(font);
        text.setCharacterSize(characterSize);
        text.setFillColor(textColor);

        outputText.setFont(font);
        outputText.setCharacterSize(characterSize);
        outputText.setFillColor(textColor);

        //shape
        shape.setPosition(sf::Vector2f(0, 0));
        shape.setSize(sf::Vector2f(100, 100));
        shape.setFillColor(sf::Color::Red);
    }

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered) {
                handleTextEntered(event);
            }
        }
    }

    void update() {
        drawText(inputPosition);
        drawOutputText(outputPosition);
    }

private:
    sf::RenderWindow& window;
    sf::Font font;
    unsigned int characterSize;
    sf::Color textColor;
    sf::Text text;
    sf::Text outputText;
    std::string userInput;
    sf::Vector2f inputPosition;
    sf::Vector2f outputPosition;
    sf::RectangleShape shape;
    const unsigned int maxInputLength = 2; // Maksymalna d³ugoœæ wprowadzanego tekstu

    void handleTextEntered(const sf::Event& event) {
        if (event.text.unicode < 128 && userInput.length() < maxInputLength) {
            if (event.text.unicode == 8 && !userInput.empty()) {
                userInput.pop_back(); // Backspace, usuwanie ostatniego znaku
            }
            else if (event.text.unicode == 13) {
                // Enter, dodaj obs³ugê dla wciœniêcia klawisza Enter
                outputText.setString("User Input: " + userInput);
                std::cout << "User Input: " << userInput << std::endl;
                userInput.clear();
            }
            else {
                userInput += static_cast<char>(event.text.unicode);
            }

            text.setString(userInput);
        }
    }

    void drawText(const sf::Vector2f& position) {
        text.setPosition(position);
        window.draw(shape);
        window.draw(text);
    }

    void drawOutputText(const sf::Vector2f& position) {
        //window.draw(outputText);
        outputText.setPosition(position);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Text Input");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return -1;
    }

    TextInput textInput(window, font, 24, sf::Color::White, sf::Vector2f(10, 10), sf::Vector2f(10, 40));

    while (window.isOpen()) {
        textInput.handleEvents();
        window.clear();
        textInput.update();
        window.display();
    }

    return 0;
}
