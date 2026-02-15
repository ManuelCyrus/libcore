#include <stdio.h>
#include <stdlib.h>

/*! 
*@brief core_lenght return the all length of one string 
*/  
int core_strlen(char *str){

    int i = 0;

    if(!str){
        return 0;
    }

    while (str[i] != '\0')
    {
        i++;
    }
    
    return i;
}


/*! 
*@brief check if the character is alphabet
*/ 
int core_is_alphabet(char c){

    return((c>='a' && c<='z') || (c>='A' && c<='Z') );

}



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

    int strlen = core_length(s1)+core_length(s2);
    char *new = malloc((strlen+1)*sizeof(char));
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



