#include "../include/ui.h"
#include "../include/game.h"
#include "../include/scores.h"
#include <raylib.h>
#include <stdio.h>

static Color fondo = {4, 21, 61, 255}; 
static Color colorCasilla = {237, 241, 245, 255};
static Color colorNumero = {238, 108, 77, 255};
static Color panel = {60, 120, 170, 255};

//dibujar tablero

void dibujarTablero(estado *e) {
	int inicioX = 60;
	int inicioY = 80;
	int tam = 100;
	int espacio = 10;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			int x = inicioX + j * (tam + espacio);
			int y = inicioY + i * (tam + espacio);

			DrawRectangle(x, y, tam, tam, colorCasilla);

			if (e->tabla2048[i][j] != 0) {
				char texto[10];
				sprintf(texto, "%d", e->tabla2048[i][j]);

				DrawText(texto, x + 30, y + 30, 28, colorNumero);
			}
		}
	}
}


