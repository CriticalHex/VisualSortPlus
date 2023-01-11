#include<SFML/Graphics.hpp>
#include<iostream>
#include"Selection.h"
#include<random>
#include<ctime>

using namespace std;


int main() {

    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(0, 0), "Graphical Sorting", sf::Style::Fullscreen);
    sf::Event event;
    sf::Color bgColor = sf::Color(8, 6, 12);

    Selection sort(window, window.getSize().x, false);

    while (window.isOpen()) {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                window.close();
            }

        }

        window.clear(bgColor);

        sort.run(window, 100);

        window.display();
    }

}