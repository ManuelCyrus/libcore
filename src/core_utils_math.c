/* This only will include all utils function necessay to work with number*/
#include "../include/core.h"

/**
 * @brief Macro to allow printing with a default precision of 2 
 * if only one argument is provided.
 */



/*
 * @brief This function prints a number in the standard output
 * 
 * @param number The integer to be printed
 */
void core_putnbr(int number){

    if( number < 0){
        core_putchar('-');
        number = -number;
    }
    if(number >= 10){
        core_putnbr(number/10);
    }
    core_putchar((number%10)+'0');
}

/*
 * @brief This function prints a number in the standard output
 * 
 * @param number The integer to be printed
 */
void core_putnbr_unsigned(unsigned int number){

    if(number >= 10)
        core_putnbr_unsigned(number/10);
    core_putchar(number % 10 + '0');
   
}





/**
 * @brief This function print float in std output
 * * */
void core_putfloat(double nbr, ...){

    va_list arg;

    va_start(arg,nbr);

    int value = va_arg(arg,int) ;
    int count = value ? value: 5;

     
    int i = 0;
    core_putnbr((int)(nbr));

    if(nbr < 0){
        nbr = - nbr;
    }
    
    double newnbr= nbr - (int)(nbr);

    write(1,".",1);

    while (i <= count)
    {     

         newnbr = newnbr -(int)newnbr;
         newnbr *= 10;
        
         int value = (int)(newnbr);

        core_putnbr(value);

        i++;
    }
    

    
    va_end(arg);
    
 }



/**
*@brief Check if  is number
*/
int core_is_digit(char c){
    return( (c >= '0' && c<='9') || (c >= 0 && c <= 9));
}


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
 * @brief This function counts the length of the numbers in decimal base
 * 
 * @param n The integer to be measured
 * @return int The number of digits
 */
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



/**
*@brief This function check if the number is prime
**/
int core_is_prime(int nbr){

    int factor = 2;

    while(nbr > factor ){

        if(nbr % factor == 0 ){
            return(0);
        }

        factor++;

    }

    return (1);
}


//exponentiation

/**
 * @brief Calculate the base raised to the exponent
 * */
int core_pow(int base, int expo){

    int i = 1;
    int b = base;

    while (i < expo)
    {
        base = base*b;
        i++;
    }
    
    return (base);

}




/**
 * @brief Returns the absolute value of the integer x.
 * 
 * @param x The integer to check.
 * @return The positive magnitude of x.
 */
int  core_abs(int x){
    

    if(x < 0){
        x = -x;
    }

    return(x);
}

/**
 * @brief Returns the absolute value of a floating-point number.
 * 
 * @param x The float value to process.
 * @return float The non-negative magnitude of x.
 */
float  core_fabs(int x){
    

    if(x < 0){
        x = -x;
    }

    return(x);
}

/**
 * @brief Returns the floating-point remainder of a / b.
 * 
 * @param a The numerator (dividend).
 * @param b The denominator (divisor).
 * @return float The remainder of the division.
 */
double  core_fmod(int a,int b){
    
    int singnal = 1;

    if(a < 0){
        singnal = -singnal;
    }
    a = a % b; 

    return(a * singnal);
}


/**
 * @brief return the square of the number 
 */
/* int core_sqrt(int x){

}

*/

