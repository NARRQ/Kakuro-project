#include "CotoKakuro.h"
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include "Text.hpp"
#include <locale>
#include"Button.h"

void CotoKakuro::OpenWindow() {
    sf::RenderWindow window;
    window.create(sf::VideoMode(600, 400), "Co to Kakuro?");

    //font
    sf::Font font=setFont();
    // Load text from file
    std::ifstream file("text_file_cotokakuro.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    //read text from file
    std::string textContent;
    std::string line;
    while (std::getline(file, line)) {
        textContent += line + '\n';
    }
    file.close();

    //wrap text
    float maxWidth = 400.0f;
    textContent = wrapText(textContent, font, 24, maxWidth);

    //set text
    sf::Text text{};
    text.setFont(font);
    text.setString(textContent);
    text.setCharacterSize(24);
    
    //create button exit
    Button button_exit(sf::Vector2f(400, 300), sf::Vector2f(200, 50), font, "Wyjscie");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || button_exit.isClicked(event,window))
                window.close();
        }
        window.clear(sf::Color(128, 128, 128));
        button_exit.draw(window);
        window.draw(text);
        window.display();
    }


}