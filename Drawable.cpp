#include "Drawable.h"
#include "Window.h"

Drawable::Drawable()
{
    this->toWorld.identity();
}

Drawable::~Drawable()
{
    //
}

void Drawable::draw()
{
    std::cout << "Warning: draw() is not implemented" << std::endl;
}
