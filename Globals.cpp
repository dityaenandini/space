#include "Globals.h"

DrawData Globals::drawData;
UpdateData Globals::updateData;

Camera Globals::camera = Camera();
Light Globals::light = Light();

Texture Globals::bg;

Sphere Globals::sphere = Sphere(5, 25, 25);

OBJObject Globals::ship = OBJObject();
OBJObject Globals::enemy = OBJObject();
OBJObject Globals::astro = OBJObject();