#include <iostream>
#include <cmath>
#include "vec3.h"

// Constructor
// Default values
vec3::vec3()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

// Alternate constructor that creates a type of vec3
// to store x, y, z coordinates
vec3::vec3(double xc, double yc, double zc)
{
    x = xc;
    y = yc;
    z = zc;
}

// Deconstructor
vec3::~vec3()
{
    //dtor
}

// Function to add two vectors together
vec3 vec3::AddedVectors(vec3 vec1, vec3 vec2)
{

    x = vec1.x + vec2.x;
    y = vec1.y + vec2.y;
    z = vec1.z + vec2.z;

    return vec3(x, y, z);
}

// Function to display the x, y, z coordinates of a
// vec3
void vec3::Display()
{
    std::cout << x << ", " << y << ", " << z << std::endl;
}

/*vec3 vec3::Rotation()
{
    double xRotationMatrix[3][3] = {1,   0,     0,
                                    0, cos(y), -sin(z),
                                    0, sin(y),  cos(z)};

    double yRotationMatrix[3][3] = {cos(x), 0, sin(z),
                                      0,    1,   0,
                                   -sin(x), 0, cos(z)};

    double xyzMatrix[3] = {x, y, z};

    return vec3(x, y, z);
} */