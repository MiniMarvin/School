#include <unistd.h>
#include <time.h>

#define ns 	*1
#define us 	*1
#define ms 	*1000

//portable function to clean terminal screen
void cleanScreen(){
	
	
	#ifdef __MINGW32 
		system("cls");		//windows
	#else 				
		system("clear");	//linux
	#endif
}

//shuffle the array ramdomly
void shuffletArray(int* arrPtr, int arraySize){
	int i = 0;
	int buff, buffRand0, buffRand1;

	if(arraySize > 1){
		//make a toggle with random positions
		for(i = 0 ; i < arraySize*2; i++){
			
			//randomize a position in array
			buffRand0 = rand()%arraySize;
			buffRand1 = rand()%arraySize;
			
			//togle the values in the random positions
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
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' && stdin != NULL );
}