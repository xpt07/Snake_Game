#include "..\include\Snake.h"  // Includes the Snake header

/*******************************************************************************************************************************************************

                   This calculates the distance between two points in a 2D plane using the Distance formula derived from Pythagorean theorem

********************************************************************************************************************************************************/
float Snake::dist(float x1, float y1, float x2, float y2)
{
    float D = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return D;
}

Snake::Snake() {
    /************************************************************************************************************

                                Sets sizes, colors, position... Of the diferent shapes

    ************************************************************************************************************/
    snakebody.setSize(Vector2f(size, size));
    snakebody.setFillColor(Color::Green);

    snakehead.setFillColor(Color::Green);
    snakehead.setSize(Vector2f(size, size));
    snakehead.setPosition(Sx, Sy);

    transsnakeb.setFillColor(Color::Red);
    transsnakeb.setSize(Vector2f(10, 10));
    transsnakeb.setOutlineColor(Color::Black);
    transsnakeb.setOutlineThickness(1);
}


float Snake::getdirx() {
    return dirx; // returns snake's direction in the x axis
}

float Snake::getdiry() {
    return diry;  // returns snake's direction in the y axis
}

float Snake::getSx()
{
    return Sx;  // returns Sx
}

float Snake::getSy()
{
    return Sy;  // returns Sy
}

void Snake::IncLength() {
    length++;  // Increments length
}

// Changes the direction of the snake according to User input
void Snake::snakeMovement(int x, int y) {
    dirx = x;
    diry = y;
}

void Snake::SnakeEatSelf(RenderWindow& window)
{
    for (int i = 0; i < int(tail.size()); i++) {
        Vector st = tail.at(i);
        float s = dist(Sx, Sy, st.x, st.y);  // This will calculate the distance between the head coords and any body coords.
        if (s < 1) {  // If that distance is less than 1 the window closes
            window.close();
        }
    }
}

// Updates the position of the snake
void Snake::tick(RenderWindow& window) {
    if (length > 0) {
        if (length == int(tail.size()) && (int(tail.size()) != 0)) {
            tail.erase(tail.begin());
        }
        Vector st(Sx, Sy);
        tail.push_back(st);
    }

    Sx = Sx + (dirx * size);   // Incriments snake position by scale and speed
    Sy = Sy + (diry * size);   //
}

// Draws all snake parts
void Snake::drawSnake(RenderWindow& window) {
    for (int i = 0; i < int(tail.size()); ++i) {
        snakebody.setPosition(Vector2f(tail.at(i).x, tail.at(i).y));  // Sets the position of the snake's body parts according to the length of the tail
        transsnakeb.setPosition(Vector2f((tail.at(i).x), (tail.at(i).y)));  // Sets the position of the snake's body parts according to the length of the tail
        window.draw(snakebody);  // Draws the snake's body
        window.draw(transsnakeb);    // Draws the snake's body
    }
    snakehead.setPosition(Vector2f(Sx, Sy));  // Sets the position of the snake's head
    window.draw(snakehead);  // Draws the head
}