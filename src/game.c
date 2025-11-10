#include "../include/game.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

// VerificarMovimiento
// - Recibe arreglos de linea del tablero
// - Desplaza numeros hacia la izquierda
// - Suma numeros iguales
// - Devuelve el nuevo arreglo de numeros, el puntaje y detecta si se hizo un movimiento o no
//

ResultadoMovimiento VerificarMovimiento(int serie[N], int puntosActuales) {
	ResultadoMovimiento r;
	int i, j;

	for (i = 0; i < N; i++) {
		r.nuevaSerie[i] = serie[i];
	}

	r.nuevosPuntos = puntosActuales;
	r.movio = false;

	//busca movimientos
	
	for (i = 0; i < N; i++) {

		if (r.nuevaSerie[j] == 0) {
			continue;
		}


		if (r.nuevaSerie[i] == 0) {
			r.nuevaSerie[i] = r.nuevaSerie[j];
			r.nuevaSerie[j] = 0;
			r.movio = true;
			continue;
		}


