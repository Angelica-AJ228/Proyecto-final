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

void ui_run(estado *e) {

	InitWindow(760, 500, "Juego 2048");
	SetTargetFPS(60);

	float acumulador = 0; //guarda el tiempo

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		acumulador += dt;

		if (acumulador >= 1.0f) { //aumenta el tiempo y reinicia el conteo
			e->tiempo++;
			acumulador = 0;
		}

		if (!e->ganador && !e->perdido) { //cuando se apretan las teclas de direccion
			if (IsKeyPressed(KEY_LEFT)) mover(e, 'E');
			if (IsKeyPressed(KEY_RIGHT)) mover(e, 'D');
			if (IsKeyPressed(KEY_UP)) mover(e, 'A');
			if (IsKeyPressed(KEY_DOWN)) mover (e, 'S');
		}

		if (e->ganador || e->perdido) { //una vez se gana o pierde se puede reiniciar con Enter
			if (IsKeyPressed(KEY_ENTER)) {
				guardarPuntaje(e->puntos);
				TableroVacio(e)
			}
		}

		BeginDrawing();
		ClearBackground(fondo);

		dibujarTablero(e);
		dibujarPanel(e);

		if (e->ganador) {
			DrawText("Ganaste! (ENTER)", 200, 400, 32, YELLOW);
		} else if (e->perdido) {
			DrawText("Perdiste (ENTER)", 200, 400, 32, RED);
		}

		EndDrawing();

	}

	CloseWindow();

}




