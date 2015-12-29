#ifndef __GUTIL

    #define __GUTIL
    #include "gutil.c"
    

    /**
     * @brief clean the terminal screen.
     * @details portable function to clean terminal screen, because, the native functions based on system.
     * aren't portable between windows and linux.
     */
    void cleanScreen();
    
    /**
     * @brief shuffle ramdomly an int array.
     * @details that function shuffle an int array ramdomly, based in a buble sort algorithm.
     * 
     * @param arrPtr Pointer to the array.
     * @param arraySize Size of the array(avoid any kind of segmentation fault error).
     */
    void shuffletArray(int* arrPtr, int arraySize);
    
    /**
     * @brief portable function to stop terminal for a while.
     * @details That function makes the system sleep for some time based on the value recieved in milisseconds.
     * 
     * @param long the sleeping time.
     */
    void sleepms(unsigned long int sleepmsTime);
    
    /**
     * @brief potable function to flush stdin
     * @details sometimes, when we are capturing data from the user, we have to flush the input buffer(stdin)
     * to do that in a portable way, we can use this function.
     */
    void flush_in();

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
    int getLine (char *prmpt, char *buff, size_t sz);

#endif