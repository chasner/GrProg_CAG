#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

// The Amount of Rectangles needed, to build the Matchfield
const int amountRectangles = 49;

// This boolean is used to prevent multiple serializations off the Matchfield
bool hasMatchfieldCreated = false;

// This Vector consists off every 
std::vector<sf::RectangleShape> matchshapes(49);

// This Function builds a 7 x 7 Matchfield
void CreateMatchfield(int _ShapesToRender)
{
	if (hasMatchfieldCreated == false)
	{
		for (int i = 1; i < 8; i++)
		{
			for (int j = 1; j < 8; j++)
			{
				std::cout << "Creating Square[" << i << "][" << j << "]\n";
				// Create Square[i][j] 
			}
		}
		hasMatchfieldCreated = true;
	}
	
}


int main()
{
	std::cout << "Welcome to the Game! \n";

	// Creates the window for the game. The player should only be able to close and move the window. Titlebar / Resize
	sf::RenderWindow gamewindow(sf::VideoMode(800, 800),"Abgabe_CAG", sf::Style::Close | sf::Style::Titlebar);



	CreateMatchfield(2);

	
	// Gameloop
	while (gamewindow.isOpen())
	{
		
		sf::Event mainEvent;
		while (gamewindow.pollEvent(mainEvent))
		{
			switch (mainEvent.type)
			{
			case sf::Event::Closed:
				gamewindow.close();
				break;

			case sf::Event::Resized:
				std::cout << "New Resolution: " << mainEvent.size.width << "x" << mainEvent.size.height << "\n";
				break;

			case sf::Event::TextEntered:
				if (mainEvent.text.unicode < 128)
				{
					printf("%c", mainEvent.text.unicode);
				}
				

			default:
				break;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//sf::Vector2i mousePos = sf::Mouse::getPosition(gamewindow);
			//defaultDot2.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		}


		gamewindow.clear(sf::Color::Black);



		
		
		gamewindow.display();
	}

	return 0;
}