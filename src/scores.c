#include "../include/scores.h"
#include <stdio.h>

//guarda el top5 de notas
void guardarPuntaje(int p) {
	
	FILE *f = fopen("puntuaciones.txt", "a");
	
	if (f == NULL) return;
	
	fprintf(f, "%d\n", p);
	
	fclose(f);
}


