#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "control.h"
#include "askuser.h"
#include "graphiclib.h"
#include "common.c"

int main(void){
	
	//declare variables
	FILE *f;
	int i = 0, j = 0;
	int* buffer;
	double* soma;

	//get the values that we need to the program
	int qn = qNum();
	int st = showTime();
	int rn = turnNum();
	int ew = model();

	soma = malloc(qn);

	//plot a space between the games
	f = fopen("results.txt", "a+");
	fprintf(f, "\n\n\n");
	fclose(f);

	//make the turn procedure as long as we don't reach the selected number of turns
	for(i = 0; i < rn; i++){
		buffer = turn(st, ew, qn, "results.txt");
		for(j = 0; j < qn; j++){
			soma[j] += (double) buffer[j];
		}
	}
	//Allegro area~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	ALLEGRO_BITMAP* dbuf;

	allegroStart();

	ALLEGRO_DISPLAY* display;
	display = al_create_display(640, 480);
	if (!display) {
		abort_example("Error creating display\n");
	}

	ALLEGRO_COLOR black = al_map_rgb_f(0.0, 0.0, 0.0);
	ALLEGRO_COLOR white = al_map_rgb_f(1.0, 1.0, 1.0);
	ALLEGRO_COLOR background = al_map_rgb_f(0.5, 0.5, 0.6);

	dbuf = al_create_bitmap(640, 480);

	if(!dbuf){
		abort_example("Error creating double buffer\n");
	}

	al_set_target_bitmap(dbuf);
	al_clear_to_color(background);

	drawGraphic(soma, dbuf, qn, white);

	flip(dbuf, display);
	char bstring[20];
	getLine("digite o nome do arquivo: ", bstring, 20);

	//if(al_save_bitmap("graphic.png", dbuf)) printf("imagem escrita com sucesso!\n");
	//else printf("erro escrevendo graphic.png\n");
	if(al_save_bitmap(strcat(bstring, ".png"), dbuf)) printf("imagem escrita com sucesso!\n");
	else printf("erro escrevendo: %s", bstring);

	getchar();


	al_destroy_bitmap(dbuf);

	//if windows, stop the program up to digit a key
	#ifdef _WIN32
		system("pause");
	#endif
	
	return 0;
	
}