# Proyecto-final

En este repositorio se puede encontrar un codigo en programacion C del juego 2048 usando interfaz grafica, aqui hay un vasto uso de punteros y tambien incorporauna biblioteca externa Raylib

Requisitos para instalar el juego:

-La biblioteca Raylib: 
	-Asegurarse de tener la version de Ubuntu .. y la version de Raylib ..

Para compilar todo:

-Asegurate de estar dentro de Proyecto final
-Ejecuta "make"
-Esto va a crear un ejecutable llamado "juego"

Para ejecutar:
-En la consola de comandos escribe "./juego"
-Aparece una ventana con el juego

Para limpiar:
-Si quieres eliminar el ejecutable, escribe "make clean" en tu consola de comandos

Para jugar:
-Debes llegar hasta el numero 2048, los puntos van aumentando con cada movimiento. Para hacerlo usa las flechas de arriba, abajo, derecha e izquierda del teclado de tu dispositivo.
-Al ganar o al perder, el juego va a poner un mensaje seguido de la palabra "ENTER", si quieres guardar el puntaje y reiniciar el juego apreta "ENTER", si no sal de la ventana en la esquina superior derecha.
-Si guardaste el puntaje, este te aparecera automaticamente en el panel lateral derecho

Caracteristicas generales:
-Juego 2048 en version de Raylib
-Ventana expandible
-Guarda top5 puntuajes en archivo puntuaciones.txt y se actualiza con cada juego
