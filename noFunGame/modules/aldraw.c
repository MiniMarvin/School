/*
 * This example exercises line drawing, and single buffer mode.
 */

#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "common.c"

/* XXX the software line drawer currently doesn't perform clipping properly */

const int W = 640;
const int H = 480;

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_COLOR black;
ALLEGRO_COLOR white;
ALLEGRO_COLOR background;
ALLEGRO_BITMAP *dbuf;

int last_x = -1;
int last_y = -1;

//function prototypes
int* drawcartesian(ALLEGRO_BITMAP *bitmap);
void drawGraphic(double* points, ALLEGRO_BITMAP *bitmap);
int getArraySize(double* array);
int getMax(double* points, int size);

static void flip(void);


static void red_dot(int x, int y)
{
   al_draw_filled_rectangle(x - 2, y - 2, x + 2, y + 2, al_map_rgb_f(1, 0, 0));
}

int main(int argc, const char *argv[])
{
   if (!al_init()) {
      abort_example("Could not init Allegro.\n");
   }

   if(!al_init_image_addon()){
      abort_example("Could not init the image addon.\n");
   }


   display = al_create_display(W, H);
   if (!display) {
      abort_example("Error creating display\n");
   }

   black = al_map_rgb_f(0.0, 0.0, 0.0);
   white = al_map_rgb_f(1.0, 1.0, 1.0);
   background = al_map_rgb_f(0.5, 0.5, 0.6);

   if (argc > 1 && 0 == strcmp(argv[1], "--memory-bitmap")) {
      al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
   }
   dbuf = al_create_bitmap(W, H);
   if (!dbuf) {
      abort_example("Error creating double buffer\n");
   }

   al_set_target_bitmap(dbuf);
   al_clear_to_color(background);
   

   //int* zero = drawcartesian(dbuf);
   //printf("\n%i,%i\n", zero[0], zero[1]);

   double values[6] = {0,4,2,8,6,10};
   double* points = (double*) &values;
   drawGraphic(points, dbuf);


   flip();
   
   if(al_save_bitmap("blah.png", dbuf)) printf("imagem escrita com sucesso!\n");
   else printf("erro escrevendo blah.png\n");

   getchar();

   al_destroy_bitmap(dbuf);

   return 0;
}

static void flip(void)
{
   al_set_target_backbuffer(display);
   al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ZERO);
   al_draw_bitmap(dbuf, 0.0, 0.0, 0);
   al_flip_display();
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//functoin that draws a cartesian graph structure
int* drawcartesian(ALLEGRO_BITMAP *bitmap){
	al_set_target_bitmap(bitmap);
	
	int w = al_get_bitmap_width(bitmap);
	int h = al_get_bitmap_height(bitmap);

	static int zero[2];
	zero[0] = 20;
	zero[1] = h-20;

	al_draw_line(20, 0, 20, h, white, 0);
	al_draw_line(0, h-20, w, h-20, white, 0);

	return zero;

}

//function to write a function denoted by f(point) in cartesian graphic
void drawGraphic(double* points, ALLEGRO_BITMAP *bitmap){

   int i = 0;

   int w = al_get_bitmap_width(bitmap);
   int h = al_get_bitmap_height(bitmap);

   //int size = getArraySize(points);
   int size = 6;
   
   int max = getMax(points, size);

	int* zero = drawcartesian(bitmap);

   int xstep =  (w-20)/size;
   int ystep =  (h-20)/max;

   double ynow;

   printf("size:%i, max:%i\n", size, max);
   printf("w:%i, h:%i\n", w,h);
   printf("xstep: %i, ystep:%i\n", xstep, ystep);

   al_set_target_bitmap(bitmap);

   for(i = 0; i < size; i++){
      //red_dot((i+zero[0])*xstep, (i+points[i])*ystep);
      //al_draw_line((i+zero[0])*xstep, (zero[1]+points[i])*ystep, (i+1+zero[0])*xstep, (zero[1]+points[i+1])*ystep ,white,0);
      //printf("from: (%i,%i)\n", (i+zero[0])*xstep, (zero[1]+points[i])*ystep);
      //printf("to: (%i,%i)\n", (i+1+zero[0])*xstep, (zero[1]+points[i+1])*ystep);
      
      red_dot((i)*xstep + zero[0], (-points[i])*ystep + zero[1]);
      al_draw_line(i*xstep + zero[0], -points[i]*ystep + zero[1], (i+1)*xstep + zero[0], -(points[i+1])*ystep + zero[1],white,0);
      printf("from: (%i,%i)\n", i*xstep + zero[0], -points[i]*ystep + zero[1]);
      printf("to: (%i,%i)\n", (i+1)*xstep + zero[0], -(points[i+1])*ystep + zero[1]);
   }


/*
   
   double max = getMax(points);

	double stepx = w/size;
   double stepy = h/max;
*/
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
