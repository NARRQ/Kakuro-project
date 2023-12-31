//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//class TextInputRectangle {
//public:
//    TextInputRectangle(float x, float y, float width, float height)
//        : rectangle(sf::Vector2f(width, height)), isTextInputActive(false) {
//        rectangle.setPosition(x, y);
//        rectangle.setFillColor(sf::Color::Green);
//
//        if (!font.loadFromFile("arial.ttf")) {
//            std::cerr << "Failed to load font" << std::endl;
//        }
//
//        text.setFont(font);
//        text.setCharacterSize(20);
//        text.setPosition(x + 10, y + 10);
//        text.setFillColor(sf::Color::Black);
//    }
//
//    void handleEvent(const sf::Event& event, sf::RenderWindow& window) {
//        if (event.type == sf::Event::MouseButtonPressed) {
//            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//
//            if (rectangle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
//                isTextInputActive = true;
//            }
//            else {
//                isTextInputActive = false;
//            }
//        }
//        else if (event.type == sf::Event::TextEntered) {
//            if (isTextInputActive) {
//                if (event.text.unicode == 8 && !inputText.empty()) {
//                    // Backspace: usuñ ostatni znak
//                    inputText.pop_back();
//                }
//                else if (event.text.unicode < 128) {
//                    // Dodaj wprowadzony znak do tekstu
//                    inputText += static_cast<char>(event.text.unicode);
//                }
//
//                text.setString(inputText);
//            }
//        }
//    }
//
//    void draw(sf::RenderWindow& window) const {
//        window.draw(rectangle);
//        window.draw(text);
//    }
//
//private:
//    sf::RectangleShape rectangle;
//    sf::Text text;
//    sf::Font font;
//    bool isTextInputActive;
//    std::string inputText;
//};
//
//class MainWindow {
//public:
//    MainWindow(unsigned int width, unsigned int height, const std::string& title)
//        : window(sf::VideoMode(width, height), title) {}
//
//    void run() {
//        TextInputRectangle inputRectangle(300, 250, 200, 100);
//
//        while (window.isOpen()) {
//            sf::Event event;
//            while (window.pollEvent(event)) {
//                if (event.type == sf::Event::Closed) {
//                    window.close();
//                }
//
//                inputRectangle.handleEvent(event, window);
//            }
//
//            window.clear();
//            inputRectangle.draw(window);
//            window.display();
//        }
//    }
//
//private:
//    sf::RenderWindow window;
//};
//
//int main() {
//    MainWindow mainWindow(800, 600, "SFML Text Input");
//    mainWindow.run();
//
//    return 0;
//}
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>
//#include "PoledoWpisania.h"
//class MacierzSFML {
//public:
//    MacierzSFML(int liczbaWierszy, int liczbaKolumn) : liczbaWierszy(liczbaWierszy), liczbaKolumn(liczbaKolumn) {
//        // Inicjalizacja macierzy prostok¹tów
//        prostokaty.resize(liczbaWierszy, std::vector<sf::RectangleShape>(liczbaKolumn));
//
//        // Inicjalizacja macierzy okrêgów
//        okregi.resize(liczbaWierszy, std::vector<sf::CircleShape>(liczbaKolumn));
//        //inicjacja pola
//        pole.resize(liczbaWierszy, std::vector<PoledoWpisania>(liczbaKolumn));
//
//        // Inicjalizacja pozycji prostok¹tów i okrêgów w macierzy
//        for (int i = 0; i < liczbaWierszy; ++i) {
//            for (int j = 0; j < liczbaKolumn; ++j) {
//                prostokaty[i][j].setSize(sf::Vector2f(50, 50));
//                prostokaty[i][j].setPosition(j * 60, i * 60);
//                prostokaty[i][j].setFillColor(sf::Color::Blue);
//
//                okregi[i][j].setRadius(25);
//                okregi[i][j].setPosition(j * 60, i * 60);
//                okregi[i][j].setFillColor(sf::Color::Red);
//            }
//        }
//    }
//
//    // Metoda do wyœwietlania macierzy
//    void Wyswietl(sf::RenderWindow& okno) {
//        for (int i = 0; i < liczbaWierszy; ++i) {
//            for (int j = 0; j < liczbaKolumn; ++j) {
//                okno.draw(prostokaty[i][j]);
//                okno.draw(okregi[i][j]);
//            }
//        }
//    }
//
//private:
//    int liczbaWierszy;
//    int liczbaKolumn;
//    std::vector<std::vector<sf::RectangleShape>> prostokaty;
//    std::vector<std::vector<sf::CircleShape>> okregi;
//    std::vector<std::vector<PoledoWpisania>> pole;
//
//};
//
//int main() {
//    const int liczbaWierszy = 3;
//    const int liczbaKolumn = 4;
//
//    sf::RenderWindow okno(sf::VideoMode(300, 200), "SFML Macierz");
//
//    MacierzSFML mojaMacierz(liczbaWierszy, liczbaKolumn);
//
//    while (okno.isOpen()) {
//        sf::Event zdarzenie;
//        while (okno.pollEvent(zdarzenie)) {
//            if (zdarzenie.type == sf::Event::Closed) {
//                okno.close();
//            }
//        }
//
//        okno.clear();
//        mojaMacierz.Wyswietl(okno);
//        okno.display();
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//const int N = 8; // Rozmiar planszy NxN
//
//// Struktura reprezentuj¹ca komórkê planszy
//struct Cell {
//    int value;
//    vector<int> possibilities;
//};
//
//// Funkcja do wypisywania planszy
//void printBoard(const vector<vector<Cell>>& board) {
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            cout << board[i][j].value << " ";
//        }
//        cout << endl;
//    }
//}
//
//// Funkcja do generowania planszy Kakuro
//vector<vector<Cell>> generateKakuroBoard() {
//    // Inicjalizacja planszy
//    vector<vector<Cell>> board(N, vector<Cell>(N, { 0, {1, 2, 3, 4, 5, 6, 7, 8, 9} }));
//
//    // Dodawanie wskazówek numerycznych (np. co drugi wiersz i kolumna)
//    for (int i = 0; i < N; i += 2) {
//        for (int j = 0; j < N; j += 2) {
//            // Przyk³adowe wskazówki - mo¿na dostosowaæ do w³asnych potrzeb
//            board[i][j].value = rand() % 9 + 1;
//            board[i + 1][j + 1].value = rand() % 9 + 1;
//        }
//    }
//
//    // Generowanie planszy
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            // Pomijaj komórki z wskazówkami numerycznymi
//            if (i % 2 == 0 && j % 2 == 0) {
//                continue;
//            }
//
//            // Wybieranie losowej kombinacji z mo¿liwoœci
//            if (!board[i][j].possibilities.empty()) {
//                int index = rand() % board[i][j].possibilities.size();
//                board[i][j].value = board[i][j].possibilities[index];
//            }
//        }
//    }
//
//    return board;
//}
//
//int main() {
//    // Inicjalizacja generatora liczb pseudolosowych
//    srand(time(0));
//
//    // Generowanie planszy Kakuro
//    vector<vector<Cell>> kakuroBoard = generateKakuroBoard();
//
//    // Wypisanie planszy
//    printBoard(kakuroBoard);
//
//    return 0;
//}
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

<<<<<<< Updated upstream
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
=======
class PlanszaKakuro {
public:
    PlanszaKakuro(int rozmiar);
    void Wyswietl();
    // Dodaj inne metody zwi¹zane z plansz¹ Kakuro, jeœli to konieczne

private:
    int rozmiar;
    std::vector<std::vector<int>> plansza;
    void GenerujPlansze();
    void WypelnijPlansze();
};

PlanszaKakuro::PlanszaKakuro(int rozmiar) : rozmiar(rozmiar) {
    plansza.resize(rozmiar, std::vector<int>(rozmiar, 0));
    GenerujPlansze();
    WypelnijPlansze();
}

void PlanszaKakuro::GenerujPlansze() {
    // Generator liczb pseudolosowych
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Logika generowania planszy (mo¿na dostosowaæ)
    // W tym przyk³adzie, wype³niamy pierwsz¹ kolumnê i pierwszy wiersz liczbami pseudolosowymi
    for (int i = 0; i < rozmiar; ++i) {
        plansza[i][0] = std::rand() % 9 + 1; // Liczby od 1 do 9
        plansza[0][i] = std::rand() % 9 + 1;
    }
}

void PlanszaKakuro::WypelnijPlansze() {
    // Logika wype³niania planszy (mo¿na dostosowaæ)
    // W tym przyk³adzie, wype³niamy pozosta³e komórki planszy
    for (int i = 1; i < rozmiar; ++i) {
        for (int j = 1; j < rozmiar; ++j) {
            plansza[i][j] = plansza[i][0] + plansza[0][j];
        }
    }
}

void PlanszaKakuro::Wyswietl() {
    for (int i = 0; i < rozmiar; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            std::cout << plansza[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rozmiarPlanszy = 5;
    PlanszaKakuro plansza(rozmiarPlanszy);

    plansza.Wyswietl();
>>>>>>> Stashed changes

    return 0;
}
