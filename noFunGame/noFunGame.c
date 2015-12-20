#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define maxValue 20
#define ns 	*1
#define us 	*1
#define ms 	*1000

FILE *f;


//prototypes
int qNum();
int showTime();
unsigned int model();
int turnNum();
void turn(int st, int rn, int ew, int qn);
void writeInFile(int array[], int arraySize);
void cleanScreen();
void shuffletArray(int* arrPtr, int arraySize);
void sleepms(unsigned long int sleepmsTime);
void flush_in();

int main(int argc, char const *argv[]){

	int i = 0;

	int qn = qNum();
	int st = showTime();
	int rn = turnNum();
	int ew = model();


	f = fopen("results.txt", "a+");
	fprintf(f, "\n\n\n\n\n\n");
	fclose(f);
	
	for(i = 0; i < rn; i++){
		turn(st, rn, ew, qn);
	}
	

	#ifdef __MINGW32
		system("pause");
	#endif
	
	//fclose(f);
	
	return 0;
}

//define the number of questions
int qNum(){
	int qn = 0;
	printf("PRESS ANY KEY TO CONTINUE");
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

	do{
		cleanScreen();
		flush_in();
		printf("digite o modelo de exibição\n 0 - em linha \n 1 - em colunas\n");
		scanf("%i", &model);
	} while(model >= 2);
	
	return model;
}

//run the turn - plot the numbers and them make the asks and plot the turn result in the file
void turn(int st, int rn, int ew, int qn){

	srand(time(NULL));

	int* numbers;
	int* num0;
	int* answers;
	
	numbers = malloc(qn);
	num0 = malloc(qn);
	answers = malloc(qn);
	
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

	writeInFile(answers, qn);
}

void writeInFile(int array[], int arraySize){
	f = fopen("results.txt", "a+");
	int i, j;
	
	for(i = 0; i < arraySize; i++){
		for(j = 0; j < 4; j++){
			fprintf(f, "_");
		}
	}
	
	fprintf(f, "\n");
	fprintf(f, "|");
	
	//fprintf(f, "\n");
	for(i = 0; i < arraySize; i++){
		fprintf(f, " %i |", array[i]);
	}
/*
	for(i; i < 20; i++){
		fprintf(f, "   |");
	}
*/
	fprintf(f, "\n");
	

	fclose(f);
}


//portable function to clean terminal screen
void cleanScreen(){
	#ifdef __MINGW32
		system("cls");
	#else
		//system("reset");
		system("clear");
	#endif
}

//shuffle the array ramdomly
void shuffletArray(int* arrPtr, int arraySize){
	int i = 0;
	int buff, buffRand0, buffRand1;

	if(arraySize > 1){
		//make a toggle with random positions
		for(i = 0 ; i < arraySize*2; i++){
			buffRand0 = rand()%arraySize;
			buffRand1 = rand()%arraySize;
			buff = arrPtr[buffRand0];
			arrPtr[buffRand0] = arrPtr[buffRand1];
			arrPtr[buffRand1] = buff;
		}
	}

}

void sleepms(unsigned long int sleepTime){
	//sleepms terminal for a time in microseconds
	usleep(sleepTime);
}

//clean the stdin
void flush_in() { 
   int ch = 0;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' && stdin != NULL ){}
   /*while( (ch = getchar()) != EOF && ch != '\n' ){
   		if (ch == 0) break;
   } */
}

