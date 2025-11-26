#include "../include/ui.h"
#include "../include/game.h"
#include "../include/scores.h"
#include <raylib.h>
#include <stdio.h>

//Este codigo es la intefaz grafica por lo que se manejan colores, para ello tenemos las primeras cuatro variables

static Color fondo = {4, 21, 61, 255}; 
static Color colorCasilla = {237, 241, 245, 255};
static Color colorNumero = {238, 108, 77, 255};
static Color panel = {60, 120, 170, 255};

//dibujar tablero

void dibujarTablero(estado *e, int inicioX, int inicioY, int tam, int espacio) {

	for (int i = 0; i < N; i++) { //marca los margenes para dibujar el tablero, esta en pixeles
		for (int j = 0; j < N; j++) {
			
			int x = inicioX + j * (tam + espacio);
			int y = inicioY + i * (tam + espacio);
			
			DrawRectangleRounded((Rectangle){x, y, tam, tam}, 0.2f, 8, colorCasilla);
			
			if (e->tabla2048[i][j] != 0) {
				char texto[10];
				sprintf(texto, "%d", e->tabla2048[i][j]);
				
				DrawText(texto, x + 30, y + 30, 28, colorNumero);
			}
		}
	}
}

void dibujarPanel(estado *e, int panelX, int panelY) {
	
	DrawRectangleRounded((Rectangle){panelX, panelY, 220, 300}, 0.25f, 12, panel);
	char puntos[32];
	
	sprintf(puntos, "Puntos: %d", e->puntos); //dibuja el texto en el panel de la derecha, puntos es el primero
	DrawText(puntos, panelX + 20, panelY + 30, 22, WHITE);
	
	char tiempo[32]; //dibuja el campo para el tiempo
	sprintf(tiempo, "Tiempo: %d s", e->tiempo);
	DrawText(tiempo, panelX + 20, panelY + 70, 22, WHITE);
	
	//top5
	int top[5];
	int cant = 0;
	obtenerTop5(top, &cant);
	
	DrawText("Top 5:", panelX + 20, panelY +120, 22, WHITE);
	
	for (int i = 0; i < cant; i++) {
		char t[32];
		sprintf(t, "%d. %d", i + 1, top[i]);
		DrawText(t, panelX +20, panelY + 150 + i * 30, 20, WHITE);
	}
}

void ui_run(estado *e) {
	
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 600, "Juego 2048"); //ventana inicial mas grande para que se vea completo sin expandir
	SetTargetFPS(60);

	float acumulador = 0; //guarda el tiempo

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		acumulador += dt;

		if (acumulador >= 1.0f) { //aumenta el tiempo y reinicia el conteo
			e->tiempo++;
			acumulador = 0;
		}

		if (!e->ganador && !e->perdido) { //detecta cuando se apretan las teclas de direccion
			if (IsKeyPressed(KEY_LEFT)) mover(e, 'E');
			if (IsKeyPressed(KEY_RIGHT)) mover(e, 'D');
			if (IsKeyPressed(KEY_UP)) mover(e, 'A');
			if (IsKeyPressed(KEY_DOWN)) mover (e, 'S');
		}

		if (e->ganador || e->perdido) { //una vez se gana o pierde se puede reiniciar con Enter, y solo con enter por eso hay una instruccion
			if (IsKeyPressed(KEY_ENTER)) {
				guardarPuntaje(e->puntos);
				TableroVacio(e);
			}
		}

		//para hacer dinamico el tablero y centrar
		int tam = 100;
		int espacio = 10;

		int anchoTablero = N * tam + (N - 1) * espacio;

		int inicioX = (GetScreenWidth() - anchoTablero) / 2;
		if (inicioX < 20) inicioX = 20; //minimo margen
		int inicioY = 80;

		int margen = 20;
		int panelAncho = 220;
		int panelX, panelY;

		if (GetScreenWidth() >= anchoTablero + panelAncho + 3 * margen) {
			panelX = inicioX + anchoTablero + margen;
			panelY = inicioY;
		} else {
			panelX = (GetScreenWidth() - panelAncho) / 2;
			panelY = inicioY + anchoTablero + margen;
		}


		BeginDrawing();
		ClearBackground(fondo);

		dibujarTablero(e, inicioX, inicioY, tam, espacio); //aqui redibuja el tablero segun lo que se aumento
		dibujarPanel(e, panelX, panelY);//aqui dibuja el panel

		int mensajeY = inicioY + anchoTablero + 40; //mensajes al final de cada partida
		if (e->ganador) {
			const char *txt = "Ganaste! (Presiona ENTER para guardar)";
			int w = MeasureText(txt, 32);
			DrawText(txt, (GetScreenWidth() - w) / 2, mensajeY, 32, WHITE); //posicion del texto
		} 
		
		else if (e->perdido) {
			const char *txt = "Perdiste! (Presiona ENTER para guardar)";
			int w = MeasureText(txt, 32);
			DrawText(txt, (GetScreenWidth() - w) / 2, mensajeY, 32, RED);
		}

		EndDrawing();

	}

	CloseWindow();

}




