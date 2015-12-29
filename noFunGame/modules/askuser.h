#ifndef __ASKUSER

    #define __ASKUSER
    
    #include "askuser.c"
    
    /**
     * @brief define the number of questions that will be made to the user
     * @details make a question to the user asking for this value
     * @return the number of questions
     */
    int qNum();
    
    /**
     * @brief get the time exibition in screen from user terminal
     * @details make a question to the user asking for a value in miliseconds, just works with positive values
     * @return the question's exibition time
     */
    int showTime();
    
    /**
     * @brief get the number of turns in wich the user will be avalied
     * @details in every turn is shown a serie of numbers, the number of turns delimits the 
     *          amount of times it will occur
     * @return the number of turns in wich the user will be exposed
     */
    unsigned int model();
    
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
    int turnNum();
    
#endif

