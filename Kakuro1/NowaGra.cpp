#include "NowaGra.h"

std::list<PoleBlanc> NowaGra::getpolaBlanc()
{
	return std::list<PoleBlanc>();
}

void NowaGra::addPoleBlanc(PoleBlanc poleblanc)
{
	polaBlanc.push_back(poleblanc);
}

std::list<PoledoWpisania> NowaGra::getpoladoWpisania()
{
	return std::list<PoledoWpisania>();
}

void NowaGra::addPoledoWpisania(PoledoWpisania poledowpisania)
{
	poladoWpisania.push_back(poledowpisania);
}

void NowaGra::wypiszObjekty(sf::RenderWindow& window)
{
	//render objektow
	for (PoleBlanc poleblanc:polaBlanc)
	{
		poleblanc.DrawPoleBlanc(window);
	}
	for (PoledoWpisania poledowpisania: poladoWpisania)
	{
		poledowpisania.draw(window);
	}
}

void NowaGra::wypiszEventy(const sf::Event& event, sf::RenderWindow& window)
{
	for (auto& poledowpisania : poladoWpisania)
	{
		poledowpisania.handleEvent(event, window);
	}
}

void NowaGra::CzyscListy()
{
	polaBlanc.clear();
	poladoWpisania.clear();
}

void NowaGra::UtworzListy(int m,sf::Font& font, bool uzupelniaj)
{
	if (rozwiazanie == nullptr) {
		CzysclisteMatrix();
	}
	CzyscListy();
	if (!uzupelniaj)
	{
		UtworzMacierzRozwiazan(m);
	}
	textSprawdz.setString("");
	//utworzenie objektów
	//wiersze
	for (float i = 0; i < liczbaWierszy_przypadek; i++)
	{
		//kolumny
		for (float j = 1; j < liczbaKolumn; j+=2)
		{
			liczba_do_matrix = rozwiazanie[(int)i][(int)j];
			liczba_do_mapy_objektow = rozwiazanie[(int)i][(int)j-1];
			//pole puste
			if (liczba_do_mapy_objektow <= 0 && liczba_do_matrix <= 0 )
			{
				PoleBlanc poleblanc(sf::Vector2f(30 + j * 30, 60 * i + 30), font, "","");
				addPoleBlanc(poleblanc);
			}
			//pole blank
			else if (liczba_do_mapy_objektow != 0)
			{
				if (liczba_do_mapy_objektow==-1)
				{
					//tylko wiersz
					PoleBlanc poleblanc(sf::Vector2f(30 + j * 30, 60 * i + 30), font, "", std::to_string(liczba_do_matrix));
					addPoleBlanc(poleblanc);
				}
				else if (liczba_do_matrix <= 0 )
				{
					//tylko kolunma
					PoleBlanc poleblanc(sf::Vector2f(30 + j * 30, 60 * i + 30), font,std::to_string(liczba_do_mapy_objektow),"");
					addPoleBlanc(poleblanc);
				}
				else
				{
					//all
					PoleBlanc poleblanc(sf::Vector2f(30 + j * 30, 60 * i + 30), font, std::to_string(liczba_do_mapy_objektow), std::to_string(liczba_do_matrix));
					addPoleBlanc(poleblanc);
				}
			}
			//pole do wpisania
			else if (liczba_do_mapy_objektow == 0 && liczba_do_matrix != 0)
			{
				PoledoWpisania poledowpisania((int)j,(int)i,sf::Vector2f(30 + j * 30, 60 * i + 30), font);
				if (uzupelniaj)
				{
					poledowpisania.setvalue(liczba_do_matrix);
				}
				addPoledoWpisania(poledowpisania);
			}
		}
	}
}

void NowaGra::UtworzMacierzRozwiazan(const int& przypadek)
{
	int suma = 0;
	liczbaWierszy_przypadek = przypadek;
	liczbaKolumn = 2 * przypadek;
	//utworzenie macierzy
	rozwiazanie = new int* [liczbaWierszy_przypadek];
	for (int i = 0; i < liczbaWierszy_przypadek; ++i) {
		rozwiazanie[i] = new int[liczbaKolumn];
	}

	//wprowadzenie danych
	switch (liczbaWierszy_przypadek)
	{
	case 3:case 4:
			//plansza 3x3 i 4x4
			for (int i = liczbaWierszy_przypadek - 1; i >-1; --i)
			{
				for (int j = liczbaKolumn - 1; j >-1; j-=2)
				{
					if (i==0 && j==1)
					{
						rozwiazanie[i][j] = -1;
						rozwiazanie[i][j-1] = -1;
					}
					//suma
					else if (i == 0)
					{
						//wiersz
						//pola blank
						rozwiazanie[i][j] = -1;
						suma = 0;
						for (int ii = 1; ii < liczbaWierszy_przypadek; ii++)
						{
							suma += rozwiazanie[ii][j];
							rozwiazanie[i][j-1] = suma;
						}

					}
					else if (j==1)
					{
						//kolumna
						//pola blank
						rozwiazanie[i][j-1] = -1;
						suma = 0;
						for (int jj = 3; jj < liczbaKolumn; jj += 2)
						{
							suma += rozwiazanie[i][jj];
							rozwiazanie[i][j] = suma;
						}
					}
					else
					{
						//pole do wpisania
						rozwiazanie[i][j-1] = 0;
						do
						{
							liczba = GeneratorWarunku(1, 9);
							czysarozne = true;
							//sprawdzenie czy jest rozna w wierszu i kolumnie
							//wiersz
							for (int iii = liczbaWierszy_przypadek - 1; iii > 0; iii--)
							{
								if (rozwiazanie[iii][j] == liczba)
								{
									czysarozne = false;
									break;
								}
							}
							//kolumna
							for (int jjj = liczbaKolumn - 1; jjj > 0; jjj-=2)
							{
								if (rozwiazanie[i][jjj] == liczba)
								{
									czysarozne = false;
									break;
								}
							}
							if (czysarozne)
							{
								rozwiazanie[i][j] = liczba;
							}

						} while (!czysarozne);
					}
				}
			}
			break;
		case 7:
			for (int i = liczbaWierszy_przypadek - 1; i > -1; --i)
			{
				for (int j = liczbaKolumn - 1; j > 0; j -= 2)
				{
					//wiersz 0 lub kolumna 0
					if (i == 0 || j == 1)
					{
						//warunki dla pola blank
						//min dwa pola do wpisania
						if (
							//kolumna
							i < liczbaWierszy_przypadek - 2 &&
							rozwiazanie[i + 1][j] != 0 && rozwiazanie[i + 2][j] != 0 &&
							rozwiazanie[i + 1][j - 1] == 0 && rozwiazanie[i + 2][j - 1] == 0
							)
						{
							//suma kolumna
							suma = 0;
							for (int ii = i + 1; ii < liczbaWierszy_przypadek; ii++)
							{
								if (rozwiazanie[ii][j - 1]!=0)
								{
									break;
								}
								suma += rozwiazanie[ii][j];
							}
							rozwiazanie[i][j - 1] = suma;
						}
						else
						{
							rozwiazanie[i][j - 1] = -1;
						}
						if (
							//wiersz
							j < liczbaKolumn - 1 &&
							rozwiazanie[i][j + 2] != 0 && rozwiazanie[i][j + 4] != 0 &&
							rozwiazanie[i][j + 1] == 0 && rozwiazanie[i][j + 3] == 0
							)
						{
							//suma wiersz
							suma = 0;
							for (int jj = j + 2; jj < liczbaKolumn; jj += 2)
							{
								if (rozwiazanie[i][jj - 1] !=0 )
								{
									break;
								}
								suma += rozwiazanie[i][jj];
							}
							rozwiazanie[i][j] = suma;
						}
						else
						{
							rozwiazanie[i][j] = -1;
						}

					}
					else if (
						(i > liczbaWierszy_przypadek * 2 / 3 && j > (liczbaKolumn) * 2 / 3)	//prawy dolny
						|| (i > liczbaWierszy_przypadek * 2 / 3 && j <= (liczbaKolumn) / 3 + 1)	//lewy dolny
						|| (i <= liczbaWierszy_przypadek * 2 / 3 && i > liczbaWierszy_przypadek / 3 && j > (liczbaKolumn) / 3 + 1 && j <= (liczbaKolumn) * 2 / 3)	//srodek srodek
						|| (i <= liczbaWierszy_przypadek / 3 && j > (liczbaKolumn) * 2 / 3)//prawy gorny
						|| (i <= liczbaWierszy_przypadek / 3 && j <= (liczbaKolumn) / 3 + 1)//lewy gorny
						)	//skrajne rogi
					{
						//pole do wpisania
						rozwiazanie[i][j - 1] = 0;
						do
						{
							liczba = GeneratorWarunku(1, 9);
							czysarozne = true;
							//kolunma
							for (int iii = i; iii <= liczbaWierszy_przypadek - 1; iii++)
							{
								if (rozwiazanie[iii][j] == liczba)
								{
									czysarozne = false;
									break;
								}
							}
							//wiersz
							for (int jjj = j; jjj <= liczbaKolumn - 1; jjj += 2)
							{
								if (rozwiazanie[i][jjj] == liczba)
								{
									czysarozne = false;
									break;
								}
							}
							if (czysarozne)
							{
								rozwiazanie[i][j] = liczba;
							}

						} while (!czysarozne);
					}
					//srodki
					else
					{
						if (GeneratorWarunku(0, 1))
						{
							//warunki dla pola blank
							//min dwa pola do wpisania
							if (
								//kolumna
								i < liczbaWierszy_przypadek - 2 &&
								rozwiazanie[i + 1][j] != 0 && rozwiazanie[i + 2][j] != 0 &&
								rozwiazanie[i + 1][j - 1] == 0 && rozwiazanie[i + 2][j - 1] == 0
								)
							{
								//suma kolumna
								suma = 0;
								for (int ii = i+1; ii < liczbaWierszy_przypadek; ii ++)
								{
									if (rozwiazanie[ii][j - 1] != 0 )
									{
										break;
									}
									suma += rozwiazanie[ii][j];
								}
								rozwiazanie[i][j - 1] = suma;
							}
							else
							{
								rozwiazanie[i][j - 1] = -1;
							}
							if (
								//wiersz
								j < liczbaKolumn - 1 &&
								rozwiazanie[i][j + 2] != 0 && rozwiazanie[i][j + 4] != 0 &&
								rozwiazanie[i][j + 1] == 0 && rozwiazanie[i][j + 3] == 0
								)
							{
								//suma wiersz
								suma = 0;
								for (int jj = j + 2; jj < liczbaKolumn; jj+=2)
								{
									if (rozwiazanie[i][jj-1] != 0)
									{
										break;
									}
									suma += rozwiazanie[i][jj];
								}
								rozwiazanie[i][j] = suma;
							}
							else
							{
								rozwiazanie[i][j] = -1;
							}
						}
						else
						{
							//pole do wpisania
							rozwiazanie[i][j - 1] = 0;
							do
							{
								liczba = GeneratorWarunku(1, 9);
								czysarozne = true;
								//kolunma
								for (int iii = i; iii <= liczbaWierszy_przypadek-1; iii++)
								{
									if (rozwiazanie[iii][j] == liczba)
									{
										czysarozne = false;
										break;
									}
								}
								//wiersz
								for (int jjj = j; jjj <= liczbaKolumn-1; jjj+=2)
								{
									if (rozwiazanie[i][jjj] == liczba)
									{
										czysarozne = false;
										break;
									}
								}
								if (czysarozne)
								{
									rozwiazanie[i][j] = liczba;
								}

							} while (!czysarozne);
						}

					}
				}
			}
		break;
	}
}

int NowaGra::GeneratorWarunku(const int poczatek, const int koniec)
{
	//generator liczb losowych
	// Utworzenie generatora liczb pseudolosowych
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dis(poczatek, koniec);
	return dis(gen);
}

void NowaGra::Sprawdz(const sf::Font& font)
{
	if (rozwiazanie != nullptr)
	{
		//inicjacja textu Sprawdz
		textSprawdz.setFont(font);
		textSprawdz.setCharacterSize(30);
		textSprawdz.setPosition(100,430);
		std::list<PoledoWpisania>::iterator it = poladoWpisania.begin();
		int suma_kontrolna{};
		int suma_usera{};
		int nr_pola{};
		int WprowadzoneWartosci[10] = {};
		int iloscWprowadzonych = 0;
		for (int i = 0; i < liczbaWierszy_przypadek && it != poladoWpisania.end(); i++)
		{
			for (int j = 1; j < liczbaKolumn; j += 2)
			{
				//sprawdzenie po kolumnie
				if (rozwiazanie[i][j-1]>0)
				{
					suma_kontrolna = rozwiazanie[i][j - 1];
					suma_usera = 0;
					iloscWprowadzonych = 0;
					nr_pola = i + 1;
					it = poladoWpisania.begin();
					while (nr_pola<liczbaWierszy_przypadek && rozwiazanie[nr_pola][j-1]==0)
					{
						if (it->getValue() == 0)
						{
							//nie uzupelniona
							textSprawdz.setString("Uzupelnij tabele");
							textSprawdz.setFillColor(sf::Color::Black);
							return;
						}
						else if (it->getIdW() == nr_pola && it->getIdK()==j)
						{
							//dodaj
							//sprawdz czy wartosci sa rozne
							for (int ii = 0; ii < 10; ii++)
							{
								if (WprowadzoneWartosci[ii] == it->getValue())
								{
									//ZLE
									textSprawdz.setString("SPROBUJ JESZCZE RAZ");
									textSprawdz.setFillColor(sf::Color(128, 0, 0));
									return;
								}
							}
							WprowadzoneWartosci[iloscWprowadzonych] = it->getValue();
							suma_usera += it->getValue();
							nr_pola++;
							iloscWprowadzonych++;
						}
						else
						{
							it++;
						}
					}
					if (suma_kontrolna!=suma_usera)
					{
						//ZLE
						textSprawdz.setString("SPROBUJ JESZCZE RAZ");
						textSprawdz.setFillColor(sf::Color(128, 0, 0));
						return;
					}
				}
				//sprawdzenie po wierszu
				if (rozwiazanie[i][j - 1] != 0 && rozwiazanie[i][j]>0)
				{
					suma_kontrolna = rozwiazanie[i][j];
					suma_usera = 0;
					iloscWprowadzonych = 0;
					nr_pola = j+2;
					it = poladoWpisania.begin();
					while (nr_pola < liczbaKolumn && rozwiazanie[i][nr_pola - 1] == 0)
					{
						if (it->getValue() == 0)
						{
							//nie uzupelniona
							textSprawdz.setString("Uzupelnij tabele");
							textSprawdz.setFillColor(sf::Color::Black);
							return;
						}
						else if (it->getIdK() == nr_pola && it->getIdW() == i)
						{
							//dodaj
							//sprawdz czy wartosci sa rozne
							for (int ii = 0; ii < 10; ii++)
							{
								if (WprowadzoneWartosci[ii] == it->getValue())
								{
									//ZLE
									textSprawdz.setString("SPROBUJ JESZCZE RAZ");
									textSprawdz.setFillColor(sf::Color(128, 0, 0));
									return;
								}
							}
							WprowadzoneWartosci[iloscWprowadzonych] = it->getValue();
							suma_usera += it->getValue();
							nr_pola+=2;
							iloscWprowadzonych++;
						}
						else
						{
							it++;
						}
					}
					if (suma_kontrolna != suma_usera)
					{
						//ZLE
						textSprawdz.setString("SPROBUJ JESZCZE RAZ");
						textSprawdz.setFillColor(sf::Color(128, 0, 0));
						return;
					}
				}
			}
		}
		// Dobrze
		textSprawdz.setString("LAMIGLOWKA ROZWIAZANA POPRAWNIE!");
		textSprawdz.setFillColor(sf::Color(0, 0, 128));
	}
}

void NowaGra::Autouzupelnij(sf::Font& font)
{
	if(rozwiazanie!=nullptr)
	{
		UtworzListy(0, font, true);
		CzysclisteMatrix();
	}
}

void NowaGra::CzysclisteMatrix()
{
	for (int i = 0; i < liczbaWierszy_przypadek; ++i) {
		delete[] rozwiazanie[i];
	}
	delete[] rozwiazanie;
	liczbaWierszy_przypadek = 0;
	liczbaKolumn = 0;
	rozwiazanie = nullptr;
}

void NowaGra::SprawdzNapis(sf::RenderWindow& window) const
{
	// Rysowanie tekstu na ekranie
	window.draw(textSprawdz);
}
