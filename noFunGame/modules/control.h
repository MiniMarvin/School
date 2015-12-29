#ifndef __CONTROL
    #define __CONTROL
    
    #include "control.c"
    
	/**
		\brief control a turn of the game
		that game shows a serie of numbers to the user every turn in wich the game executs
		in these turns, the user has to answer some questions about if he sawn the numbers in the screen
		these number have been all shown to the user, them if he answers yes, automatically the program
		registers the answer as 1, but, if he didn't, the answer becomes to zero, like that, we have an
		binary answer array.
		run the turn - plot the numbers and them make the asks and plot the turn result in the file

		\param[in] st the time in wich every number will be shown up

		\param[in] ew 
		\parblock
		control the exibition way of the numbers in the round, if 0-line,1-colum
		0:
		num1 num2 num3 num4

		1:
		num1
		num2
		num3
		num4
		\endparblock

		\param[in] qn the number of questions in the game. there will be a result for every question

		\param[out] file the file in wich we will write the round result
		\return return the array containing the results of the game
	 */
    int* turn(int st, int ew, int qn, char* file);
    
#endif