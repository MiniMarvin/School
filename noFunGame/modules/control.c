#include "gutil.h"
#include "filecontrol.h"

//run the turn - plot the numbers and them make the asks and plot the turn result in the file
void turn(int st, int rn, int ew, int qn, char* file){

	srand(time(NULL));

	//Dinamically allocate the arrays~~~~~~~~~~~~~//
	int* numbers;
	int* num0;
	int* answers;
	
	numbers = malloc(qn);
	num0 = malloc(qn);
	answers = malloc(qn);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	
	int i = 0;
	char character = 0;
	

	//create the random numbers
	for(i = 0; i < qn; i++){
		numbers[i] = rand()%100;
		num0[i] = numbers[i];
	}

	//show them in colums or in lines
	for(i = 0; i < qn; i++){
		if(ew == 0) printf("%i ", numbers[i]);
		else printf("%i\n", numbers[i]);
	}

	//wait a time to the user view the numbers
	sleepms(st ms);

	cleanScreen();

	//shuffle the array
	shuffletArray(num0, qn);

	//show the numbers ramdomly
	for(i = 0; i < qn; i++) {
		do{
			cleanScreen();
			printf("Esse numero apareceu na tela? %i\n digite s se apareceu e n se não apareceu\n", num0[i]);
			character = getchar();

		} while(character != 's' && character != 'n');

		//compute if he answered yes or no
		//as te array is from showed numbers if he answer yes, he automatically is rigth
		
		if(character == 's') answers[i] = 1;
		else answers[i] = 0;
		
		
	}
	
	//write in the file the results of the round
	writeInFile(answers, qn, file);
}