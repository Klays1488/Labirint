/*
 * main.cc
 *
 *  Created on: 27 окт. 2022 г.
 *      Author: ∆идковƒя
 */
#include <iostream>
#include "Map.h"
#include "Window.h"

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Window w {1280, 600};

	w.main_loop();

	return 0;
}


