#include "gutil.h"
#define maxValue 20

//define the number of questions
int qNum(){
	int qn = 0;
	cleanScreen();
	//debug from flush_in function -when there's nothing in stdin-
	printf("PRESS ANY KEY TO CONTINUE");
	
	//loop to make the question to the user up to he digits something valid
	do{
		flush_in();
		cleanScreen();
		printf("digite o numero de questoes (o número máximo é %i)\n", maxValue);
		scanf("%i", &qn);
	} while(qn > maxValue || qn == 0);

	return qn;
}

//get the time exibition in screen
int showTime(){
	int st = 0;
	
	//loop to make the question to the user up to he digits something valid
	do{ 
		cleanScreen();
		flush_in();
		printf("digite o tempo de exibição das questoes (em milissegundos)\n");
		scanf("%i", &st);
	} while(st <= 0);
	
	return st;
}

//get the turn num
int turnNum(){
	int rn = 0;

	//loop to make the question to the user up to he digits something valid
	do{
		cleanScreen();
		flush_in();
		printf("digite o numero de rodadas\n");
		scanf("%i", &rn);
	}while(rn <= 0);
	
	return rn;
}

//define the exibition way
unsigned int model(){
	unsigned int model = 2;
	
	//loop to make the question to the user up to he digits something valid
	do{
		cleanScreen();
		flush_in();
		printf("digite o modelo de exibição\n 0 - em linha \n 1 - em colunas\n");
		scanf("%i", &model);
	} while(model >= 2);
	
	return model;
}
