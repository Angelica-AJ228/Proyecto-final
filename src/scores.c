#include "../include/scores.h"
#include <stdio.h>

//guarda el top5 de notas
void guardarPuntaje(int p) {
	
	FILE *f = fopen("puntuaciones.txt", "a");
	
	if (f == NULL) return;
	
	fprintf(f, "%d\n", p);
	
	fclose(f);
}

void obtenerTop5(int top[5], int *cantidad) {
	int lista[200];
	int n = 0;

	FILE *f = fopen("puntuaciones.txt", "r");
	if (f == NULL) {
		*cantidad = 0;
		return;
	}

	while (fscanf(f, "%d", &lista[n]) == 1) {
		n++;
	}

	fclose(f);

	for (int i = 0; i < n - 1; i++) { //ordenar por BubbleSort
		for (int j = i + 1; j < n; j++) {
			if (lista[j] > lista[i]) {
				int aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	}

	*cantidad =  (n < 5 ? n : 5); //si n < 5 entonces asigna ese n a cantidad, si es mayor no, esto ayuda con el top5

	for (int i = 0; i < *cantidad; i++) {
		top[i] = lista[i];
	}
}
