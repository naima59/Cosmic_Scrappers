#ifndef IMAGETOTEXTURE_H
#define IMAGETOTEXTURE_H

#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <math.h>
#include "resource_dir.h"

const int screenWidth = 1920;
const int screenHeight = 1080;

Texture2D ImageToTexture(const char* fileName, int resizeWidth, int resizeHeight);

#endif