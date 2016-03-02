#include "gutil.h"
#define maxValue 20


/**
 * @brief define the number of questions that will be made to the user
 * @details make a question to the user asking for this value
 * @return the number of questions
 */
int qNum(){
	int qn = 0;
	cleanScreen();
	///debug from flush_in function -when there's nothing in stdin-
	printf("PRESS ANY KEY TO CONTINUE");
	
	///loop to make the question to the user up to he digits something valid
	do{
		flush_in();
		cleanScreen();
		printf("digite o numero de questoes (o número máximo é %i)\n", maxValue);
		scanf("%i", &qn);
	} while(qn > maxValue || qn == 0);

	return qn;
}

/**
 * @brief get the time exibition in screen from user terminal
 * @details make a question to the user asking for a value in miliseconds, just works with positive values
 * @return the question's exibition time
 */
int showTime(){
	int st = 0;
	
	///loop to make the question to the user up to he digits something valid
	do{ 
		cleanScreen();
		flush_in();
		printf("digite o tempo de exibição das questoes (em milissegundos)\n");
		scanf("%i", &st);
	} while(st <= 0);
	
	return st;
}

/**
 * @brief get the number of turns in wich the user will be avalied
 * @details in every turn is shown a serie of numbers, the number of turns delimits the 
 * 			amount of times it will occur
 * @return the number of turns in wich the user will be exposed
 */
int turnNum(){
	int rn = 0;

	///loop to make the question to the user up to he digits something valid
	do{
		cleanScreen();
		flush_in();
		printf("digite o numero de rodadas\n");
		scanf("%i", &rn);
	}while(rn <= 0);
	
	return rn;
}

/**
 * @brief define the model of exibition of every turn
 * @details the model of exibition delimits if the numbers will be shown in colum or in line
 * 0:
 * num1 num2 num3
 * 1:
 * num1
 * num2
 * num3
 * @return the way in wich the numbers will be shown
 */
unsigned int model(){
	unsigned int model = 2;
	
	///loop to make the question to the user up to he digits something valid
	do{
		cleanScreen();
		flush_in();
		printf("digite o modelo de exibição\n 0 - em linha \n 1 - em colunas\n");
		scanf("%i", &model);
	} while(model >= 2);
	
	return model;
}
