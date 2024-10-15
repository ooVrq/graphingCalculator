#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class graphingCalculator {
  sf::Font font;
  string input;
public:
  graphingCalculator();
  void draw(sf::RenderWindow &window);
  void setFunction(const string &func);
  void drawFunction();
  void drawAxes(sf::RenderWindow &window);
  void drawText(sf::RenderWindow &window);
  void handleTextInput(sf::Uint32 unicode);
  float parseInput(float x);

private:
  vector<sf::Vertex> points;
  string function;
};
