#pragma once
#include "..\SFML-2.5.1\include\SFML\Graphics.hpp"
#include "..\SFML-2.5.1\include\SFML\Window.hpp"

using namespace std;  // Namespaces used
using namespace sf;   //

class Food {
private:  // Anything under private can only be used within the class

/***************These will be used as coordinates for the Food objects*********************/
	float Fx;  // Creates float Fx
	float Fy;  //Creates float Fy


public:  // Anything under public can be used outside the class

	// Default Constructor
	Food();

	// Void method used to create new coordinates and set the position of the Food objects
	void SpawnFood();

	// Void method used to draw the Food objects
	void drawFood(RenderWindow& window);

	// Used to get the x coordinate
	int getFx();

	// Used to get the Y coordinate
	int getFy();

	// Creates a rectangle shape
	RectangleShape FShape;
};