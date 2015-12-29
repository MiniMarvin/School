#ifndef __GRAPHICLIB
	#define __GRAPHICLIB 
	
	#include <math.h>
	#include <allegro5/allegro.h>
	#include <allegro5/allegro_primitives.h>

	#include "graphiclib.c"

	#include "common.c"

	/**
	 * @brief Start allegro
	 * @details Start allegro lib addons that will be necessary in the script
	 */
	void allegroStart();

	/**
	 * @brief plot a bitmap in a windows
	 * @details plot a received bitmap in a displaying windows, just can be used in GUI modes
	 * 
	 * @param dbuf the bitmap which will be ploted
	 * @param display the window where the bitmap will be displayed
	 */
	void flip(ALLEGRO_BITMAP* dbuf, ALLEGRO_DISPLAY* display);

	/**
	 * @brief puts a red dot in the determined point of a bitmap
	 * @details places a red dot in the position specified by (x,y) in the bitmap
	 * 
	 * @param x x axys
	 * @param y y axys
	 * @param dbuf bitmap where the dot will be placed
	 */
	void red_dot(int x, int y, ALLEGRO_BITMAP* dbuf);

	/**
	 * @brief create a cartesian graphic structure in a bitmap
	 * @details draw two lines to make the axys from the cartesian graphic in the passed bitmap
	 * 
	 * @param bitmap the bitmap where the cartesian axys will be added
	 * @param cor the color of the axys
	 * 
	 * @return an array saying the zeros from the graphic (x0,y0) in pixels of this bitmap
	 */
	int* drawcartesian(ALLEGRO_BITMAP *bitmap, ALLEGRO_COLOR cor);
	
	/**
	 * @brief draws a graphic over an cartesian structure
	 * @details draws in a bitmap a graphic from one f(x) represented for an array
	 * 
	 * @param points the array that have the points that will be placed in the graphic
	 * @param bitmap the bitmap where the graphic will be drawn
	 * @param arraySize the quantity of points that have to be drawn
	 * @param cor the color of the graphic
	 */
	void drawGraphic(double* points, ALLEGRO_BITMAP *bitmap, int arraySize, ALLEGRO_COLOR cor);
	
	/**
	 * @brief get the max value inside an array
	 * @details get the biggest value inside an one dimension array
	 * 
	 * @param points the pointer to the array
	 * @param size the size of the array(avoid any kind of segmentation fault)
	 * 
	 * @return the max value
	 */
	int getMax(double* points, int size);

	//get the size from an array from a pointer
	int getArraySize(double* array);
	
#endif