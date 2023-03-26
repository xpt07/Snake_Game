#include "..\include\Food.h"  // includes the Food header

Food::Food()
{
	FShape.setSize(Vector2f(10, 10)); // Sets the size of FShape
	FShape.setFillColor(Color::Red);  // Sets the Color
	FShape.setOutlineColor(Color::Black);  //Sets the Outline Color
	FShape.setOutlineThickness(1);  // Sets the thickness of the outline

}

/************************************************************************************************************
				The SpawnFood() method will radomly choose the coords of FShape and then assign them.
			This works like a chess board. It will choose a column (eg. chess' E) and a row (eg. chess' 3).
									Giving us a precise location (eg. E3)
					The +5 will centre the shape inside the white block since it is half its size

*************************************************************************************************************/

void Food::SpawnFood()
{
	Fx = ((rand() % 31) * 20) + 5; // Chooses the x coord
	Fy = ((rand() % 31) * 20) + 5;  // Chooses the y coord
	FShape.setPosition(Fx, Fy); // Sets the position
}

void Food::drawFood(RenderWindow& window)
{
	window.draw(FShape); // Draws the shape
}

int Food::getFx()
{
	return Fx; //Return Fx
}

int Food::getFy()
{
	return Fy; // returns Fy
}