#include "graphingCalculator.h"
#include <cmath>
#include <string>

graphingCalculator::graphingCalculator()
{
    drawFunction();
    if(!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf"))
        exit(-1);
}

void graphingCalculator::draw(sf::RenderWindow &window)
{
    drawAxes(window);
    drawText(window);
    window.draw(&points[0], points.size(), sf::PrimitiveType::LinesStrip);
}

void graphingCalculator::setFunction(const string &func)
{
    input = func;
    drawFunction();
}

void graphingCalculator::drawFunction()
{
    points.clear();

    for(float x = -10; x <= 10; x += 0.01)
    {
        float y = parseInput(x);
        points.emplace_back(sf::Vertex(sf::Vector2f(x * 40 + 400, -y * 40 + 300), sf::Color::Magenta));
    }
}

void graphingCalculator::drawAxes(sf::RenderWindow &window)
{
    sf::Color axisColor = sf::Color::White;

    sf::Vertex xAxis[] = {
        sf::Vertex(sf::Vector2f(0,300), axisColor),
        sf::Vertex(sf::Vector2f(800, 300), axisColor)
    };

    sf::Vertex yAxis[] = {
        sf::Vertex(sf::Vector2f(400, 0), axisColor),
        sf::Vertex(sf::Vector2f(400, 600), axisColor)
    };

    window.draw(xAxis, 2, sf::Lines);
    window.draw(yAxis, 2, sf::Lines);
}

void graphingCalculator::drawText(sf::RenderWindow &window)
{


    sf::RectangleShape textBackground(sf::Vector2f(400, 50));
    textBackground.setPosition(200, 500);
    textBackground.setFillColor(sf::Color(200, 200, 200));
    textBackground.setOutlineColor(sf::Color::Black);
    textBackground.setOutlineThickness(2);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(textBackground.getPosition().x + 10, textBackground.getPosition().y + 10);



    text.setString(input);

    window.draw(textBackground);
    window.draw(text);
}

void graphingCalculator::handleTextInput(sf::Uint32 unicode)
{
        if(unicode == '\b')
        {
            if(!input.empty())
            {
                input.pop_back();
            }
        }
        else if(unicode == '\n')
        {
            setFunction(input);
        }
        else if(unicode < 128)
        {
            input += static_cast<char>(unicode);
        }
}

float graphingCalculator::parseInput(float x)
{
    string expression = input;
    if(expression == "x")
    {
        return x;
    }
    else if(expression[0] - '0' < 10)
        return input[0] - '0';
}