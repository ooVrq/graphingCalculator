#include <iostream>
#include <SFML/Graphics.hpp>
#include "graphingCalculator.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphing Calculator");

    graphingCalculator calculator;

    while(window.isOpen())
    {

        while (window.isOpen())
        {
            // Process events
            sf::Event event;
            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            calculator.draw(window);
            window.display();
        }
    }
    return 0;
}

