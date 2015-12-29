#ifndef __FILECONTROL
    #define __FILECONTROL
    
    #include "filecontrol.c"
    
    /**
	 * @brief write the recieved array in a txt file
	 * @details write the recieved array in a txt file adding every data after any previous one
	 * 
	 * @param array the recieved array
	 * @param arraySize the size from the array that will be wroten
	 * @param file the file where the array will be wroten
	 */
    void writeInFile(int array[], int arraySize, char* file);
    
#endif