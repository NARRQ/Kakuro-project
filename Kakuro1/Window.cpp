#include "window.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

#include "Button.h"
#include "CotoKakuro.h"
#include "Text.hpp"
#include "PoleBlanc.h"
#include "PoledoWpisania.h"
#include "NowaGra.h"

void Window::ShowWindow()
{
    //crate window object
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Kakuro Game");

    //font file
    sf::Font font = setFont();

    //nowa gra
    NowaGra nowagra;

    //create rectangle button
    Button button_1(sf::Vector2f(780, 20), sf::Vector2f(200, 50), font, "Co to KAKURO?");
    Button button_2(sf::Vector2f(780, 80), sf::Vector2f(200, 50), font, "Nowa gra dla\n planszy 3x3");
    Button button_3(sf::Vector2f(780, 140), sf::Vector2f(200, 50), font, "Nowa gra dla\n planszy 4x4");
    Button button_4(sf::Vector2f(780, 200), sf::Vector2f(200, 50), font, "Nowa gra dla\n planszy 7x7");
    Button button_5(sf::Vector2f(780, 260), sf::Vector2f(200, 50), font, "Sprawdz");
    Button button_6(sf::Vector2f(780, 320), sf::Vector2f(200, 50), font, "Autouzupelnianie");
    Button button_exit(sf::Vector2f(780, 430), sf::Vector2f(200, 50), font, "Wyjscie");

    //open window
    while (window.isOpen())
    {
            //exit event
            sf::Event event;
            while (window.pollEvent(event))
            {
                //exit
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                //if button cicked
                if (button_1.isClicked(event, window)) 
                {
                    CotoKakuro kakuroepl;
                    kakuroepl.OpenWindow();
                }
                if (button_2.isClicked(event, window)) 
                {
                    nowagra.UtworzListy(3, font,false);
                }
                if (button_3.isClicked(event, window)) {
                    nowagra.UtworzListy(4, font,false);
                }
                if (button_4.isClicked(event, window)) {
                    nowagra.UtworzListy(7, font,false);
                }
                if (button_5.isClicked(event, window)) {
                    nowagra.Sprawdz(font);
                }
                if (button_6.isClicked(event, window)) {
                    nowagra.Autouzupelnij(font);
                }
                if (button_exit.isClicked(event, window)) {
                    window.close();
                }
                        

                nowagra.wypiszEventy(event, window);
                        
            }


            window.clear(sf::Color(128, 128, 128));
            //render buttons
            button_1.draw(window);
            button_2.draw(window);
            button_3.draw(window);
            button_4.draw(window);
            button_5.draw(window);
            button_6.draw(window);
            button_exit.draw(window);
            nowagra.wypiszObjekty(window);
            nowagra.SprawdzNapis(window);
            window.display();
    }
}