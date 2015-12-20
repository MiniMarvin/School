#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "control.h"
#include "askuser.h"

int main(int argc, char const *argv[]){
	
	//declare variables
	FILE *f;
	int i = 0;

	//get the values that we need to the program
	int qn = qNum();
	int st = showTime();
	int rn = turnNum();
	int ew = model();


	//plot a space between the games
	f = fopen("results.txt", "a+");
	fprintf(f, "\n\n\n");
	fclose(f);
	
	//make the turn procedure as long as we don't reach the selected number of turns
	for(i = 0; i < rn; i++){
		turn(st, rn, ew, qn, "results.txt");
	}

	//if windows, stop the program up to digit a key
	#ifdef __MINGW32
		system("pause");
	#endif
	
	return 0;
	
}