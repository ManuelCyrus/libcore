/* This only will include all utils function necessay to work with number*/
#include "../include/core.h"


/*!
*@brief This function print number in std output
*/
void core_putnbr(int number){

    if( number < 0){
        core_putchar('-');
    }

    if(number >= 10){
        core_putnbr(number/10);
    }
    
    core_putchar((number%10)+'0');
}


// ascci to int


/*!
*@brief This function convert string to int 
*/
int core_atoi(char *str){
    
    int i = 0;
    int signal = 1;
    int number = 0;
    if(str[0] == '+' || str[0] == '-'){
        if(str[0] == '-')
        {
            signal = -1;
            i++;
        }
    }

    while (str[i] != '\0')
    {

        number = number * 10 + (str[i]- '0');
        
        i++;
    }
    
    return (number*signal);
    
}


/**
*@brief This function convert int to ascii
**/
char *core_itoa(int n){


}

/** 
 * @brief This function count the length of the numbers in decimal base
 **/

 int core_number_length(int nbr){

    int i = 0;
    if(nbr == 0){
        return (0);
    }
    else if(nbr < 0){
        nbr = -nbr;
    }

    while(nbr>=10){
    
        nbr/=nbr;
        i++;
    }

    return (i);


 }