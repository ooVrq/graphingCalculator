#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class graphingCalculator {
public:
  graphingCalculator();
  void draw(sf::RenderWindow &window);
  void setFunction(const string &func);
  void drawFunction();
  void drawAxes(sf::RenderWindow &window);

private:
  vector<sf::Vertex> points;
  string function;
};
