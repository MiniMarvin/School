#include <unistd.h>
#include <time.h>
#include <string.h>

/**
 * @brief clean the terminal screen.
 * @details portable function to clean terminal screen, because, the native functions based on system.
 * aren't portable between windows and linux.
 */
void cleanScreen(){
		
	#ifdef _WIN32 
		system("cls");		//windows
	#else 				
		system("clear");	//linux
	#endif

}

/**
 * @brief shuffle ramdomly an int array.
 * @details that function shuffle an int array ramdomly, based in a buble sort algorithm.
 * 
 * @param arrPtr Pointer to the array.
 * @param arraySize Size of the array(avoid any kind of segmentation fault error).
 */
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

/**
 * @brief portable function to stop terminal for a while.
 * @details That function makes the system sleep for some time based on the value recieved in milisseconds.
 * 
 * @param long the sleeping time.
 */
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

/**
 * @brief potable function to flush stdin
 * @details sometimes, when we are capturing data from the user, we have to flush the input buffer(stdin)
 * to do that in a portable way, we can use this function.
 */
void flush_in() { 
   int ch = 0;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' && stdin != NULL );
}


////////////////////////////////////////////////////////////////////

#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2

/**
 * @brief get one line from terminal
 * @details this function make a safe aquisition from one line from the terimal, them flushing everything if
 * this line is to big to be captured.
 * 
 * @param prmpt the string that will be ploted to user before capture the line
 * @param buff the pointer to the array where the string captured will be armazened
 * @param sz the max amount of characters that the user can digit
 * @return the result status of the line capture:
 * OK: there were no problems
 * NO_INPUT: there were no input buffer
 * TOO_LONG: the digited string was too long to be captured
 */
int getLine (char *prmpt, char *buff, size_t sz) {

	int ch, extra;

	// Get line with buffer overrun protection.
	if (prmpt != NULL) {
		printf ("%s", prmpt);
		fflush (stdout);
	}
	if (fgets (buff, sz, stdin) == NULL)
		return NO_INPUT;

	// If it was too long, there'll be no newline. In that case, we flush
	// to end of line so that excess doesn't affect the next call.
	if (buff[strlen(buff)-1] != '\n') {
		extra = 0;
		while (((ch = getchar()) != '\n') && (ch != EOF))
			extra = 1;
		return (extra == 1) ? TOO_LONG : OK;
	}

	// Otherwise remove newline and give string back to caller.
	buff[strlen(buff)-1] = '\0';
	return OK;
}
