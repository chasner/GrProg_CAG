
#include "SFML\Graphics\Shape.hpp"
#include "SFML\Graphics\Text.hpp"


// These Enum contains every possible TileType. Note: It does not check if a Tile has been touched by the Ball or not.
enum ETileType 
{
	GOAL,
	BALL,
	MOVEABLE,
	UNMOVEABLE,
	DEFAULT
	//UNMOVEABLE,
	//UNTOUCHED,
	//TOUCHED
};

// The Offset between every Tile
#define TILE_OFFSET_X 50.0f
#define TILE_OFFSET_Y 50.0f


class Tile : public sf::Shape
{
public:
	Tile();

private:


};