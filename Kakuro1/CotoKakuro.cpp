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
    
    std::string textContent = 
        " Kakuro jest jak krzyzowka, w ktorej litery " 
        " tworzace slowa zastapiono cyframi. "
        " Kazde zsumowane slowo, czyli ciag cyfr "
        " w bloku Kakuro musi miec wartosc liczby wskazanej "
        " w pionowym lub poziomym bloku. "
        " Mozna uzywac wylacznie cyfr : od 1 do 9, a danej cyfry "
        " mozna uzyc tylko raz w bloku. "
        " Kazde puzzle kakuro ma tylko jedno prawidlowe rozwiazanie, "
        " ktore mozna odkryc za pomoca logicznego myslenia. ";
    

    //wrap text
    //float maxWidth = 400.0f;
    textContent = wrapText(textContent, font, 24, 500.0f);

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