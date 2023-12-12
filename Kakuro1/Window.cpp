#include "window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Button.h"
#include "CotoKakuro.h"
#include "Text.hpp"
#include "PoleBlanc.h"
#include "PoledoWpisania.h"

void Window::ShowWindow() {
    //crate window object
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Kakuro Game");
    
    //font file
    sf::Font font = setFont();

    //create rectangle button
    Button button_1(sf::Vector2f(800, 0), sf::Vector2f(200, 50), font, "Co to KAKURO?");
    Button button_2(sf::Vector2f(800, 60), sf::Vector2f(200, 50), font, "Nowa gra");
    Button button_3(sf::Vector2f(800, 120), sf::Vector2f(200, 50), font, "Autouzupelnij");
    Button button_4(sf::Vector2f(800, 180), sf::Vector2f(200, 50), font, "Sprawdz");
    Button button_5(sf::Vector2f(800, 240), sf::Vector2f(200, 50), font, "?Zatrzymaj czas?");
    Button button_exit(sf::Vector2f(800, 300), sf::Vector2f(200, 50), font, "Wyjscie");

    //pola matrix kakuro
    PoleBlanc poleblanc(sf::Vector2f(30, 30));
    PoledoWpisania poledowpisania(sf::Vector2f(80, 30));
    //open window
    while (window.isOpen())
    {
        //exit event
        sf::Event event;
        while (window.pollEvent(event))
        {
            //exit
            if (event.type == sf::Event::Closed)
                window.close();

            //if button cicked
            if (button_1.isClicked(window)) {
                std::cout << "Co to Kakuro?\n";
                CotoKakuro kakuroepl;
                kakuroepl.OpenWindow();
            }
            if (button_2.isClicked(window)) {
                std::cout << "Nowa gra\n";

            }
            if (button_3.isClicked(window)) {
                std::cout << "Autouzupelnianie\n";
            }
            if (button_4.isClicked(window)) {
                std::cout << "Sprawdz\n";
            }
            if (button_5.isClicked(window)) {
                std::cout << "?Stop czas?\n";
            }
            if (button_exit.isClicked(window)) {
                window.close();
            }
        }

        
        window.clear(); 
        //render buttons
        button_1.draw(window);
        button_2.draw(window);
        button_3.draw(window);
        button_4.draw(window);
        button_5.draw(window);
        button_exit.draw(window);
        //reder square if button clicked
        
        poleblanc.DrawPoleBlanc(window);
        poledowpisania.DrawPoledoWpisania(window);

        window.display();
        
        //return 0;
    }
}