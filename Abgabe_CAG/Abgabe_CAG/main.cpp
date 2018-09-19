// Stuff to Fix and implement:
// 1. Create a better solution to build all Tiles, including the information from the position of the tile, what tile it is and if the ball is on the tile

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

// The Amount of Rectangles needed, to build the Matchfield
const int amountRectangles = 49;

// This boolean is used to prevent multiple serializations off the Matchfield
bool hasMatchfieldCreated = false;

// This Vector consists off every 
std::vector<sf::RectangleShape> matchRectangles(49);

// This Function builds a 7 x 7 Matchfield 
void CreateMatchfield()
{
	if (hasMatchfieldCreated == false)
	{

		for (int i = 1; i < 8; i++)
		{
			for (int j = 1; j < 8; j++)
			{
				std::cout << "Creating Rectangle[" << i << "][" << j << "]\n";
				// Create Square[i][j] 
				// sf::RectangleShape Square1(25.00*i,25.00*j);
				//Square1.setFillColor(sf::Color::White);


			}
		}
		hasMatchfieldCreated = true;
	}
	
}




int main()
{
	std::cout << "Welcome to the Game! \n";

	// Creates the window for the game. The player should only be able to close and move the window. Titlebar / Resize
	sf::RenderWindow gamewindow(sf::VideoMode(750, 750),"Abgabe_CAG", sf::Style::Close | sf::Style::Titlebar);

	CreateMatchfield();

	// Refactor this!


	// Field Color
	//	(sf::Color(144, 238, 144));

	// Color Scheme for the Goal Tiles
	sf::RectangleShape square1(sf::Vector2f(50.00f, 50.00f));
	square1.setFillColor(sf::Color(190,190,190));
	square1.setOutlineThickness(-5.0f);
	square1.setOutlineColor(sf::Color::White);

	// Color Scheme for the Tile where the Ball is
	sf::RectangleShape square2(sf::Vector2f(50.00f, 50.00f));
	square2.setFillColor(sf::Color::White);
	square2.setOutlineThickness(-5.0f);
	square2.setOutlineColor(sf::Color::Black);

	// Color Scheme for the Tile where the Ball can be moved to
	sf::RectangleShape square3(sf::Vector2f(50.00f, 50.00f));
	square3.setFillColor(sf::Color::Green);
	square3.setOutlineThickness(-5.0f);
	square3.setOutlineColor(sf::Color::White);

	// Color Scheme for the Tile where the Ball cannot be moved to
	sf::RectangleShape square4(sf::Vector2f(50.00f, 50.00f));
	square4.setFillColor(sf::Color::Red);
	square4.setOutlineThickness(-5.0f);
	square4.setOutlineColor(sf::Color::White);

	sf::RectangleShape square5(sf::Vector2f(50.00f, 50.00f));
	square5.setFillColor(sf::Color::White);

	sf::RectangleShape square6(sf::Vector2f(50.00f, 50.00f));
	square6.setFillColor(sf::Color::White);

	sf::RectangleShape square7(sf::Vector2f(50.00f, 50.00f));
	square7.setFillColor(sf::Color::White);

	sf::RectangleShape square8(sf::Vector2f(50.00f, 50.00f));
	square8.setFillColor(sf::Color::White);

	sf::RectangleShape square9(sf::Vector2f(50.00f, 50.00f));
	square9.setFillColor(sf::Color::White);

	sf::RectangleShape square10(sf::Vector2f(50.00f, 50.00f));
	square10.setFillColor(sf::Color::White);
	
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

			case sf::Event::TextEntered: // Possible future need: Player typed in the mode he wants to play.
				if (mainEvent.text.unicode < 128)
				{
					printf("%c", mainEvent.text.unicode);
				}				
			default:
				break;
			}
		}

		// Refactor this -> easy solution for every rectangle
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
		{

			sf::Vector2i mousePos = sf::Mouse::getPosition(gamewindow);
			sf::Vector2f square1position = square1.getPosition();

			if (mousePos.x > 50 && mousePos.x < 100 && mousePos.y > 50 && mousePos.y < 100)
			{
				square1.setFillColor(sf::Color::Green);
				std::cout << "Player clicked: " << "square1" << "\n";
			}

			//defaultDot2.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		}


		gamewindow.clear(sf::Color(46, 139, 87));

		// Problem - Dont create 49 Fields manually!

		// Row 1
		square1.setPosition(50, 50);
		gamewindow.draw(square1);
		square2.setPosition(150, 50);
		gamewindow.draw(square2);
		square3.setPosition(250, 50);
		gamewindow.draw(square3);
		square4.setPosition(350, 50);
		gamewindow.draw(square4);
		square5.setPosition(450, 50);
		gamewindow.draw(square5);
		square6.setPosition(550, 50);
		gamewindow.draw(square6);
		square7.setPosition(650, 50);
		gamewindow.draw(square7);
		
		// Row 2
		square8.setPosition(50, 150);
		gamewindow.draw(square8);
		square9.setPosition(150, 150);
		gamewindow.draw(square9);
		square10.setPosition(250, 150);
		gamewindow.draw(square10);

		
		
		gamewindow.display();
	}

	return 0;
}