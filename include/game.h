#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#define N 4 //tamano tablero

typedef struct { //resultado de mover linea
	int nuevaSerie[N];
	int nuevosPuntos;
	bool movio;

} ResultadoMovimiento;

typedef struct { //estructura del juego
	int tabla2048[N][N];
	int puntos;
	int tiempo;
	bool ganador;
	bool perdido;
} estado;



