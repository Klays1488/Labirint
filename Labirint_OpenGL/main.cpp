/*
 * main.cpp
 *
 *  Created on: 27 ���. 2022 �.
 *      Author: ��������
 */
#include <iostream>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include "Window.h"

int main(int, char **) {

    SDL_Init(SDL_INIT_EVERYTHING);

    Window w { 1280, 600 };

    w.main_loop();

    return 0;
}


