#ifndef CSE167_Drawable_h
#define CSE167_Drawable_h

#include <iostream>
#include "Matrix4.h"
#include "DrawData.h"
#include "Material.h"
#include "UpdateData.h"
#include <float.h>
#include <math.h>
#include <vector>


class Drawable
{
    
public:
    
    Matrix4 toWorld;
	Material material;
    
    Drawable(void);
    ~Drawable(void);
    
    virtual void draw();
};

#endif
