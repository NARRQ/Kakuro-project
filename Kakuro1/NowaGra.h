#pragma once

#include<iostream>
#include<string>
#include<list>
#include<iterator>

#include"PoleBlanc.h"
#include"PoledoWpisania.h"

//TEST
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include <random>
#include"Text.hpp"

class NowaGra
{
private:
	std::list<PoleBlanc> polaBlanc;
	std::list<PoledoWpisania> poladoWpisania;
	int liczba_warunek{};
	int liczba_do_matrix{};
	int** rozwiazanie{};
	int liczba{};
	int liczbaWierszy_przypadek{};
	int liczbaKolumn{};
	bool czysarozne=true;
	sf::Text textSprawdz;
public:

	std::list<PoleBlanc> getpolaBlanc();
	void addPoleBlanc(PoleBlanc poleblanc);
	std::list<PoledoWpisania> getpoladoWpisania();
	void addPoledoWpisania(PoledoWpisania poleblanc);
	void wypiszObjekty(sf::RenderWindow& window);
	void wypiszEventy(const sf::Event& event, sf::RenderWindow& window);
	void CzyscListy();
	void UtworzListy(int m, sf::Font& font);
	void UtworzMacierzRozwiazan(const int& przypadek);
	int GeneratorWarunku(const int poczatek, const int koniec);
	void Sprawdz(const sf::Font& font);
	void SprawdzNapis(sf::RenderWindow& window) const;
	void Autouzupelnij(sf::Font& font);
	void CzysclisteMatrix();
};