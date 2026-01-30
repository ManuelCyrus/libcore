#include "../include/core.h"
/*!
*@brief function allow you to print character int std output
*/
void core_putchar(char c){

    write(1,&c,1);

}

/*!
*@brief this function allow you to print all characters of the string
*/
void core_putstr(char *str){

    for(int i = 0; str[i] != '\0'; i++){
        core_putchar(str[i]);
    }
}

