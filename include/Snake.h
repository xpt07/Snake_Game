#pragma once
#include "..\SFML-2.5.1\include\SFML\Graphics.hpp"
#include "..\SFML-2.5.1\include\SFML\Window.hpp"    // Includes all libraries and headers used
#include <vector>             //
#include "SnakeVector.h"      //

using namespace std;  // All namespaces used
using namespace sf;   //


class Snake {
private: // Anything under private can only be used within the class

/***************These will be used as coordinates for the Snake objects*********************/
    float Sx = 300;  // Creates float Sx                                                  // 
    float Sy = 300;  // Creates float Sy                                                  //


    float dirx = 1.0;  // sets the inital direction and speed of the snake
    float diry = 0.0;  //

    int length = 0;  // Stores the length of the snake

    int size = 20;  // Stores the size of one snake block

    vector<Vector> tail = {};  // Holds the positions of the tail

    float dist(float x1, float y1, float x2, float y2); // Used to calculate the distance between two points Using the Distance formula

public:  // Anything under public can be used outside the class

    // Default Constructor
    Snake();

    // Used to get the direction and speed in the x axis
    float getdirx();

    // Used to get the direction and speed in the y axis
    float getdiry();

    // Used to get the x coord
    float getSx();

    // Used to get the y coord
    float getSy();

    // Used to Increment the length of the snake
    void IncLength();

    // Used to change the direction of the snake
    void snakeMovement(int x, int y);

    // Used to calculate the distance between the Snake's head and body
    //And if they intersect close the window
    void SnakeEatSelf(RenderWindow& window);

    // Updates the snake's position
    void tick(RenderWindow& window);

    // Draws all sanke parts
    void drawSnake(RenderWindow& window);

    RectangleShape snakehead;
    RectangleShape snakebody;
    RectangleShape transsnakeb;

};