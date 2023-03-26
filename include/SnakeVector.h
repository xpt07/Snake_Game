#pragma once

// This will be used to store objects consisting of coords

class Vector {
public:// Anything under public can be used outside the class

    // Default Constructor
    Vector();

    // Initialize with X,Y Coordinates
    Vector(float x, float y);

    float x;  // Creates float x to store the x position
    float y;  // Creates float y to store the y position
};