
/**
 * @brief Start allegro
 * @details Start allegro lib addons that will be necessary in the script
 */
void allegroStart(){

	if (!al_init()) {
		abort_example("Could not init Allegro.\n");
	}

	if(!al_init_image_addon()){
		abort_example("Could not init the image addon.\n");
	}
}

/**
 * @brief plot a bitmap in a windows
 * @details plot a received bitmap in a displaying windows, just can be used in GUI modes
 * 
 * @param dbuf the bitmap which will be ploted
 * @param display the window where the bitmap will be displayed
 */
void flip(ALLEGRO_BITMAP* dbuf, ALLEGRO_DISPLAY* display){

   al_set_target_backbuffer(display);
   al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ZERO);
   al_draw_bitmap(dbuf, 0.0, 0.0, 0);
   al_flip_display();

}

/**
 * @brief puts a red dot in the determined point of a bitmap
 * @details places a red dot in the position specified by (x,y) in the bitmap
 * 
 * @param x x axys
 * @param y y axys
 * @param dbuf bitmap where the dot will be placed
 */
void red_dot(int x, int y, ALLEGRO_BITMAP* dbuf){

	al_set_target_bitmap(dbuf);
	al_draw_filled_rectangle(x - 2, y - 2, x + 2, y + 2, al_map_rgb_f(1, 0, 0));

}

/**
 * @brief create a cartesian graphic structure in a bitmap
 * @details draw two lines to make the axys from the cartesian graphic in the passed bitmap
 * 
 * @param bitmap the bitmap where the cartesian axys will be added
 * @param cor the color of the axys
 * 
 * @return an array saying the zeros from the graphic (x0,y0) in pixels of this bitmap
 */
int* drawcartesian(ALLEGRO_BITMAP *bitmap, ALLEGRO_COLOR cor){
	al_set_target_bitmap(bitmap);
	
	int w = al_get_bitmap_width(bitmap);
	int h = al_get_bitmap_height(bitmap);

	static int zero[2];
	zero[0] = 20;
	zero[1] = h-20;

	al_draw_line(20, 0, 20, h, cor, 0);
	al_draw_line(0, h-20, w, h-20, cor, 0);

	return zero;

}

/**
 * @brief draws a graphic over an cartesian structure
 * @details draws in a bitmap a graphic from one f(x) represented for an array
 * 
 * @param points the array that have the points that will be placed in the graphic
 * @param bitmap the bitmap where the graphic will be drawn
 * @param arraySize the quantity of points that have to be drawn
 * @param cor the color of the graphic
 */
void drawGraphic(double* points, ALLEGRO_BITMAP *bitmap, int arraySize, ALLEGRO_COLOR cor){

	int i = 0;

	int w = al_get_bitmap_width(bitmap);
	int h = al_get_bitmap_height(bitmap);

	int max = getMax(points, arraySize);

	int* zero = drawcartesian(bitmap, cor);

	int xstep =  (w-20)/arraySize;
	int ystep =  (h-20)/max;

	double ynow;

	printf("size:%i, max:%i\n", arraySize, max);
	printf("w:%i, h:%i\n", w,h);
	printf("xstep: %i, ystep:%i\n", xstep, ystep);

	//al_set_target_bitmap(bitmap);

	for(i = 0; i < arraySize; i++){

		red_dot((i)*xstep + zero[0], (-points[i])*ystep + zero[1], bitmap);
		al_draw_line(i*xstep + zero[0], -points[i]*ystep + zero[1], (i+1)*xstep + zero[0], -(points[i+1])*ystep + zero[1],cor,0);
		printf("from: (%i,%i)\n", i*xstep + zero[0], -points[i]*ystep + zero[1]);
		printf("to: (%i,%i)\n", (i+1)*xstep + zero[0], -(points[i+1])*ystep + zero[1]);

	}
}

//get the maximum value in an array
/**
 * @brief get the max value inside an array
 * @details get the biggest value inside an one dimension array
 * 
 * @param points the pointer to the array
 * @param size the size of the array(avoid any kind of segmentation fault)
 * 
 * @return the max value
 */
int getMax(double* points, int size){

	int max = 0;
	int i = 0;

	for(i = 0; i < size; i++){
		if(max < points[i]) max = points[i];
	}

	return max;
}

//get the size from an array
int getArraySize(double* array){
	return (int) sizeof(array)/sizeof(double);
}