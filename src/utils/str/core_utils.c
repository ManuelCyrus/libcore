#include "../../../include/core_str.h"


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


/**
 * @brief Checks if a character is an alphabetic letter (A-Z or a-z).
 * 
 * @param c The character to be evaluated.
 * @return int Returns non-zero (true) if the character is alphabetic, 0 otherwise.
 */
int core_is_alphabet(char c){

    return((c>='a' && c<='z') || (c>='A' && c<='Z') );

}


/**
 * @brief Checks if a character is a decimal digit (0-9).
 * 
 * @param c The character to be evaluated.
 * @return int Returns non-zero (true) if the character is a digit, 0 otherwise.
 */
int core_isdigit(char c){

    return ((c>='0' && c<='9'));
}

/**
 * @brief Checks if a character is alphanumeric (either a letter or a digit).
 * 
 * @param c The character to be evaluated.
 * @return int Returns non-zero (true) if the character is alphanumeric, 0 otherwise.
 */
int core_isalnum(char c){
    return( core_isdigit(c) || core_is_alphabet(c));
}

/**
 * @brief Checks if a character belongs to the standard ASCII character set.
 * 
 * @param c The character to be evaluated.
 * @return int Returns non-zero (true) if the character is in the range 0 to 127, 0 otherwise.
 */
int core_isascii(char c)
{

    return ((c >= 0 && c<= 126));

}

/**
 * @brief Checks if a character is printable, including space.
 * 
 * @param c The character to be evaluated.
 * @return int Returns non-zero (true) if the character is printable, 0 otherwise.
 */
int core_isprint(char c){
    return ((c >= 32 && c <= 126 ));
}


/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the constant byte c.
 * 
 * @param s Pointer to the block of memory to fill.
 * @param c Value to be set (interpreted as an unsigned char).
 * @param n Number of bytes to be set to the value.
 * @return void* A pointer to the memory area s.
 */
void *core_memset(void *s, int c, size_t n){

    unsigned char *p = (unsigned char *)s;
    unsigned char set  = (unsigned char)c;

    size_t i = 0;
    while(i < n){
        p[i] = set;
    }

    return (p);
}

/**
 * @brief Erases the data in the n bytes of the memory starting at s by writing zeros.
 * 
 * @param s Pointer to the block of memory to be zeroed.
 * @param n Number of bytes to set to zero.
 */
void core_bzero(void *s,size_t n){

    core_memset(s,0,n);

}



