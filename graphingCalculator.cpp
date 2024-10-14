#include "graphingCalculator.h"
#include <cmath>

graphingCalculator::graphingCalculator()
{
    setFunction("sin(x)");
    drawFunction();
}

void graphingCalculator::draw(sf::RenderWindow &window)
{
    drawAxes(window);
    window.draw(&points[0], points.size(), sf::PrimitiveType::LinesStrip);
}

void graphingCalculator::setFunction(const string &func)
{

}

void graphingCalculator::drawFunction()
{
    points.clear();

    for(float x = -10; x <= 10; x += 0.01)
    {
        float y = x * x; //Update to parse input
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