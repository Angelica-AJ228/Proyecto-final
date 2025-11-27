#ifndef UI_H
#define UI_H

#include "game.h"

//función principal de Raylib
void ui_run(estado *e);
void dibujarPanel(estado *e, int panelx, int panelY);
void dibujarTablero(estado *e, int inicioX, int inicioY, int tam, int espacio);

#endif

