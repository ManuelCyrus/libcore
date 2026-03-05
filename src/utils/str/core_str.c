#include "../../../include/core_str.h"



/*! 
*@brief core_str_join join 2 or more strings strings
*/   
char *core_str_join(char *s1, char *s2){

    if(!s1 || !s2){
        return "s";
    }
    else if(s1 && !s2){
        return s1;
    }
    else if(!s1 && s2){
        return s2;
    }

    int len = core_strlen(s1)+core_strlen(s2);
    char *new = malloc((len+1)*sizeof(char));

    if(!new)
        return ("");
    int i = 0;
    int j =0;
    while (s1[i] != '\0')
    {
        new[i] = s1[i];
        i++;
    }

    while (s2[j] != '\0')
    {
        new[i] = s2[j];
        i++;
        j++;
    }

    new[i] = '\0';
    
    return new;
}


int core_strlen_ignore(char *str,char c){

    int i = 0;
    while(*str != '\0'){

        while (*str != '\0' && *str == c) str++;
        if (*str ) i++;
        while( *str != '\0' && *str != c) str++;
    }

    return (i);
}

/**
 * @brief 
 */
/*
 char **core_split(char *str,char c){



 }
*/

 /**
 * @brief 
 */
/* char **core_trim(char *str,char c){


 }
*/



