#ifndef VEC3_H
#define VEC3_H

class vec3
{
public:

    // Cart. Coordinates
    double x;
    double y;
    double z;

    // Constructors
    vec3();
    vec3(double xc, double yc, double zc);
    // Deconstructor
    virtual ~vec3();

    // Fucntions
    vec3 AddedVectors(vec3 vec1, vec3 vec2);
    void Display();
    //vec3 Rotation();

private:

};

#endif // VEC3_H