#include "../include/SnakeVector.h"

using namespace std;

// Initializes to center of window
Vector::Vector() {
    x = 300;
    y = 300;
}

// Initializes to X,Y coordinates
Vector::Vector(float x, float y) {
    this->x = x;
    this->y = y;
}