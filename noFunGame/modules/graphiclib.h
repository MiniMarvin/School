#ifndef __GRAPHICLIB
	#define __GRAPHICLIB 
	
	#include <math.h>
	#include <allegro5/allegro.h>
	#include <allegro5/allegro_primitives.h>

	#include "graphiclib.c"

	#include "common.c"

	//draws an ordenated axys to the cartesian map
	int* drawcartesian(ALLEGRO_BITMAP *bitmap, ALLEGRO_COLOR cor);
	
	//draws a Graphic over the cartesian
	void drawGraphic(double* points, ALLEGRO_BITMAP *bitmap, int arraySize, ALLEGRO_COLOR cor);
	
	//get the size from an array from a pointer
	int getArraySize(double* array);
	
	//get the max value in an array
	int getMax(double* points, int size);
	
	//draws a red dot in a point on a bitmap
	void red_dot(int x, int y, ALLEGRO_BITMAP* dbuf);

	//init the allegro add-ons necessary to the program
	void allegroStart();

	//plot the bitmap passed in a window
	void flip(ALLEGRO_BITMAP* dbuf, ALLEGRO_DISPLAY* display);

#endif