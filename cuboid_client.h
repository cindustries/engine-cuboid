#ifndef _CUBOID_CLIENT_H_
#define _CUBOID_CLIENT_H_

#include <iostream>
#include <vector>

extern "C" {
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h> //includes OpenGL

#include "agar/core.h"
#include "agar/gui.h"
#include "agar/gui/cursors.h"
#include "agar/gui/sdl.h"
};

#include "CuboidEngine.h"
#include "shared/shared.h"
#include "client/client.h"

using namespace std;

#endif