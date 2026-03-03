#include "../include/core.h"

/**
 * @brief Writes a character to the standard output stream.
 *
 * This function is intended for low-level character output and is
 * typically used as a building block for string output functions.
 */
void core_putchar(char c){

    write(1,&c,1);

}

/**
 * @brief Prints all characters of a string.
 *
 * Iterates through the string until the null terminator ('\0') is reached
 * and prints each character.
 *
 * @param str Pointer to the string to be printed.
 */
void core_putstr(char *str){

    for(int i = 0; str[i] != '\0'; i++){
        core_putchar(str[i]);
    }
}

/**
 * @brief Returns a new string containing characters from the input string 
 *        up to (but not including) the specified delimiter.
 *
 * @param str The input string to process.
 * @param delim The delimiter character.
 * @return A newly allocated string containing characters before the delimiter.
 */
char *core_firstworld(char *str,char delim){
        
    ssize_t len = core_strlen(str);
    char *newworld = malloc((len+1)*(sizeof(char)));
    for(int i = 0; str[i] != '\0' && str[i] != delim; i++){
        newworld[i] = str[i];
    }

    newworld[len+1] = '\0';
    return (newworld);
}

/**
 * @brief Returns a the position of one delim that we want to search in a string
 *     
 *
 * @param str The input string to process.
 * @param delim The delimiter character.
 * @return A newly allocated string containing characters before the delimiter.
 */
int core_search_delim(char *str, char delim){

    int i = 0;
    while (str[i])
    {
        if(str[i] == delim){
            return(i);
        }

        i++;
    }

    return (-1);

}


/**
 * @brief Converts a number to hexadecimal and returns a new pointer
 * 
 * @param nbr The unsigned integer to be converted
 * @param c If 'X' is Caps, if 'x' is lower
 * @return char* A pointer to the allocated string containing the hex value
 */
char *core_str_hex(unsigned int nbr,char c){

    int len =  core_number_length(nbr);
    int i = 0;
    char *str = malloc((len + 1 )* sizeof(char *));
    char *hex_low = "0123456789abcdef";
    char *hex_cap = "0123456789ABCDEF";
    
    if(nbr > 16){
        core_str_hex(nbr/16,c);
    }
    
    while (nbr!= 0)
    {

       if( c =='X'){
         str[i] = hex_cap[nbr%16];
       }
       else{
         str[i] = hex_low[nbr%16];
       }
        nbr/=16;
        i++;
    }
    
str[i] = '\0';

return (str);

}

/**
 * @brief Converts an unsigned integer to its octal (base-8) representation.
 * * @param nbr The unsigned integer to be converted.
 * @return long The octal representation of the number as a "pseudo-decimal" long.
 * * @note Warning: Using a long to store octal digits can cause overflow 
 * if the input 'nbr' is very large, as the base-10 representation 
 * grows much faster than the actual value.
 */
long core_nbr_octal(unsigned int nbr){

    long new = 0;
if(nbr>8){
   new = core_nbr_octal(nbr/8);
}

new = (new * 10) + (nbr % 8);


return (new);




}