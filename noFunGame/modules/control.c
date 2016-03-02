#include "gutil.h"
#include "filecontrol.h"


/**
	 * @brief control a turn of the game
	 * @details that game shows a serie of numbers to the user every turn in wich the game executs
		in these turns, the user has to answer some questions about if he sawn the numbers in the screen
		these number have been all shown to the user, them if he answers yes, automatically the program
		registers the answer as 1, but, if he didn't, the answer becomes to zero, like that, we have an
		binary answer array.
		run the turn - plot the numbers and them make the asks and plot the turn result in the file
	 * 
	 * @param st the time in wich every number will be shown up
	 * @param ew 
	 * control the exibition way of the numbers in the round, if 0-line,1-colum
	 *	0:
	 *	num1 num2 num3 num4
     *
	 *	1:
	 *	num1
	 *	num2
	 *	num3
	 *	num4
	 * @param qn the number of questions in the game. there will be a result for every question
	 * @param file file the file in wich we will write the round result
	 * @return the array containing the results of the game
 */	
int* turn(int st, int ew, int qn, char* file){

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

	printf("\n");
	//show them in colums or in lines
	for(i = 0; i < qn; i++){
		//printf("%i\n", ew);
		
		if(ew == 0) printf("%i ", numbers[i]);
		else printf("%i\n", numbers[i]);
	}
	fflush(stdout); // Will now print everything in the stdout buffer

	//wait a time to the user view the numbers
	sleepms(st*1000);

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

	return answers;
}