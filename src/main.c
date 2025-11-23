#include "../include/game.h"
#include "../include/ui.h"
#include <stdlib.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	
	estado e;
	TableroVacio(&e);
	ui_run(&e);
	
	return 0;
}

