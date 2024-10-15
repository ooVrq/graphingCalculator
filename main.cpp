#include <iostream>
#include <SFML/Graphics.hpp>
#include "graphingCalculator.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphing Calculator");
    window.setKeyRepeatEnabled(false);

    graphingCalculator calculator;
    while(window.isOpen()){
        // Process events
        sf::Event event;
        while(window.pollEvent(event))
        {
            // Close window: exit
            if(event.type == sf::Event::Closed)
            window.close();

            if(event.type == sf::Event::TextEntered)
            {
                calculator.handleTextInput(event.text.unicode);
            }

            // if(event.type == sf::Event::KeyPressed)
            // {
            //     if(event.key.code == sf::Keyboard::Enter)
            //     {
            //         calculator.setFunction("input");
            //     }
            // }
        }
        window.clear();
        calculator.draw(window);
        window.display();
    }
    return 0;
}

