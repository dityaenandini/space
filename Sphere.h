#ifndef CSE167_Sphere_h
#define CSE167_Sphere_h

#include <iostream>
#include "Drawable.h"

class Sphere : public Drawable
{
    
public:
    
    double radius;
    int slices, stacks;

    Sphere(double, int, int);
    
    virtual void draw();
};

#endif
