#pragma once
#include "..\SFML-2.5.1\include\SFML\Graphics.hpp" //
#include <iostream>          // Headers and libraries used
#include "Snake.h"           //
#include "Food.h"            //
#include <string>

using namespace std;  // Namespaces used
using namespace sf;   //

class Engine
{
private: // Anything under private can only be used within the class

	const float Ww = 600.0;    //
	const float Wh = 600.0;    // Sizes for window and blocks
	const int size = 20;       //

	int points = 0;  // Creates an integers to store the points
	Text pointext;  // CReates a Text object for the Score
	Font font;  // Creates a font for the text

	Snake snake;  // Creates Snake object called snake
	Food apple;   // Creates Food object called apple

	RectangleShape bg; // Creates a rectangle shape for the background boxes
	RenderWindow window;
	FloatRect snakehbounds;
	FloatRect foodbounds;

public: // Anything under public can be used outside the class

	// Default constructor
	Engine();

	// void method that takes care of running the game
	void Run();

	// void method for the losing conditions
	void EngGame(RenderWindow& window);

	// void method for the user input
	void Input();

	// void method for drawing the different objects to the screen
	void drawToScreen();

	// void method used to create and store boundaries
	void Boundaries();

};