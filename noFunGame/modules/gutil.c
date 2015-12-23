#include <unistd.h>
#include <time.h>

#define ns 	*1
#define us 	*1
#define ms 	*1000

//portable function to clean terminal screen
void cleanScreen(){
	
	
	#ifdef _WIN32 
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
	#ifndef _WIN32 //linux
	
		usleep(sleepTime);
		
	#else //windows
	
		float delay = (float)sleepTime/1000000.0;
		//just executes if there's a valid value
		if (delay > 0.0){
        	
        	//declarate the variables
			float inst1=0, inst2=0;
			
			/*get the actial time by multiplying the time from each to clock 
			cycle by the number of clock cycles*/
			inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
			
			while (inst2-inst1<delay){
		        inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
		    }
		    
		}
		
	#endif
	
}

//clean the stdin
void flush_in() { 
   int ch = 0;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' && stdin != NULL );
}