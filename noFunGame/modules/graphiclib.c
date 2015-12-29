

void allegroStart(){

	if (!al_init()) {
		abort_example("Could not init Allegro.\n");
	}

	if(!al_init_image_addon()){
		abort_example("Could not init the image addon.\n");
	}
}


void flip(ALLEGRO_BITMAP* dbuf, ALLEGRO_DISPLAY* display){

   al_set_target_backbuffer(display);
   al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ZERO);
   al_draw_bitmap(dbuf, 0.0, 0.0, 0);
   al_flip_display();

}

void red_dot(int x, int y, ALLEGRO_BITMAP* dbuf){

	al_set_target_bitmap(dbuf);
	al_draw_filled_rectangle(x - 2, y - 2, x + 2, y + 2, al_map_rgb_f(1, 0, 0));

}

//functoin that draws a cartesian graph structure
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

//function to write a function denoted by f(point) in cartesian graphic
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