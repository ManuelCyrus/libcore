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
