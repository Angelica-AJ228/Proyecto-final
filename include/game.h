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

//Declara funciones de game.c

ResultadoMovimiento VerificarMovimiento(int serie[N], int puntosActuales);
void mover(estado *e, char direccion);
void TableroVacio(estado *e);
void generarAleatorio(estado *e);
bool verificarGanador(estado *e)'
bool movimientosDisponibles(estado *e)'

#endif


