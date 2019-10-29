#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
class Button
{
public:
	sf::Sprite sprite;
	std::string name;
	sf::IntRect rect;
	Button(sf::Sprite sprite, std::string name, sf::IntRect rect);
	~Button();
};

#endif

