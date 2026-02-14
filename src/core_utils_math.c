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
 * @brief This function count the length of the numbers in decimal base
 **/
 int core_number_length(int nbr){

    int i = 0;
    if(nbr == 0){
        return (1);
    }
    else if(nbr < 0){
        nbr = - nbr;
        i++;
    }

    while(nbr >=10 ){
    
        nbr/=nbr;
        i++;
    }

    return (i);


 }

/**
*@brief This function convert int to ascii
**/
char *core_itoa(int nbr){

    int len = core_number_length(nbr);
    int i = 0;
    char *str = malloc((len+1)*sizeof(char *));

    if(nbr < 0){
        str[i] = '-';
        nbr = -nbr;
        i++;
    }

    if(nbr >= 10){
        core_itoa(nbr/10);
        
    }

    while (nbr >=10 )
    {
        str[i] = nbr % 10 + '0';
        nbr/=10;
        i++;
    }
    
    str[i] = '\0';

    return (str);


}
