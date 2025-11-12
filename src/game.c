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

void TableroVacio(estado *e) {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			e->tabla2048[i][j] = 0;
		}
	}
	
	e->puntos = 0;
	e->tiempo = 0;
	e->ganador = false;
	e->perdido = false;
	generarAleatorio(e);
	generarAleatorio(e);
}


//generar los numeros aleatorios

void generarAleatorio(estado *e) {
	
	int libres[N*N];
	int cantidad = 0;
	int i, j;
	
	for (i = 0; i < N; i++) {
		
		for (j = 0; j < N; j++) {
			if (e->tabla2048[i][j] == 0) {
				libres[cantidad] = i * 10 + j;
				cantidad++;
			}
		}
	}
	
	if (cantidad == 0) return;
	
	int pos = rand() % cantidad;
	int f = libres[pos] / 10;
	int c = libres[pos] % 10;
	int valor = (rand() % 10 < 6 ? 2 : 4); //proporcion de probabilidad de los numeros
	
	e->tabla2048[f][c] = valor;	
}
