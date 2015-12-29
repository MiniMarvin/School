#ifndef __GUTIL

    #define __GUTIL
    #include "gutil.c"
    
    //portable function to clear screen
    void cleanScreen();
    
    //function to shuffle randomly an array
    void shuffletArray(int* arrPtr, int arraySize);
    
    //function to sleep for n miliseconds
    void sleepms(unsigned long int sleepmsTime);
    
    //portable function to clean the stdin
    void flush_in();

    //function to get the line from terminal
    //\prpmt - vai ser plotado no terminal
    //\buff - ponteiro que vai recer a string
    //\sz - tamanho máximo para a string
    int getLine (char *prmpt, char *buff, size_t sz);

#endif