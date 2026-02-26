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

/*!
*@brief This function return the lengh of 
*the string
*/
int core_strlen(char *str){

    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return (i);
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
