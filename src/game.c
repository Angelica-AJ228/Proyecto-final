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
		for (j = i + 1; j < N; j++) {
			
			if (r.nuevaSerie[j] == 0) {
				continue;
			}


			if (r.nuevaSerie[i] == 0) {
				r.nuevaSerie[i] = r.nuevaSerie[j];
				r.nuevaSerie[j] = 0;
				r.movio = true;
				continue;
			}
		
			if (r.nuevaSerie[i] == r.nuevaSerie[j]) {
				int suma = r.nuevaSerie[i] + r.nuevaSerie[j];
				r.nuevaSerie[i] = suma;
				r.nuevaserie[j] = 0;
				r.nuevosPuntos += suma;
				r.movio = true;
				break;
			}
		
			break;
		}
	}
	
	return r;
}

//funcion para reiniciar tablero
