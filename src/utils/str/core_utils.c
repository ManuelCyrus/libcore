#include "../../../include/core_str.h"


/*! 
*@brief core_lenght return the all length of one string 
*/  
int core_strlen(const char *str){

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


/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * 
 * The memory areas must not overlap. Use memmove if the memory areas overlap.
 * 
 * @param dest Pointer to the destination array where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @param n Number of bytes to be copied.
 * @return A pointer to the destination (dest).
 */
void *core_memcpy(void *dest, const void *src, size_t n){

    unsigned char *new_dest = (unsigned char *)dest;
    unsigned char *new_src = (unsigned char *)src;
    while(n--){
        *new_dest++ = *new_src++;
    }

    return new_dest;
}


/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * 
 * Unlike memcpy, this function allows copying between overlapping 
 * memory areas by ensuring the data is handled safely.
 * 
 * @param dest Pointer to the destination array.
 * @param src Pointer to the source of data.
 * @param n Number of bytes to be copied.
 * @return A pointer to the destination (dest).
 */
 void *core_memmove(void *dest, const void *src, size_t n){

    unsigned char *d = (unsigned char *)dest;
    unsigned char *s = (unsigned char *)src;

    if(d < s){
        core_memcpy(d,s,n);
    }
    else{
        while (n--)
        {
            d[n] = s[n];
        }
        
    }

    return (d);

 }

 /**
 * @brief Size-bounded string copying.
 * 
 * Copies up to size - 1 characters from the NUL-terminated string src 
 * to dest, NUL-terminating the result.
 * 
 * @param dest Pointer to the destination buffer.
 * @param src Pointer to the source string.
 * @param size Total size of the destination buffer (including the space for NUL).
 * @return The total length of the string it tried to create (length of src).
 */
size_t core_strlcpy(char *dest, const char *src, size_t size){

    size_t src_len = core_strlen(src);
    if(size == 0)
        return src_len;

    int i = 0 ;
    while (src[i] !='\0' && i < (size-1))
    {
        dest[i] = src[i];
        i++;
    }
    

    dest[i] ='\0';

    return (i);

}


/**
 * @brief Size-bounded string concatenation.
 * 
 * Appends the NUL-terminated string src to the end of dest. 
 * It will append at most size - strlen(dest) - 1 bytes.
 * 
 * @param dest Pointer to the destination buffer (must contain a NUL-terminated string).
 * @param src Pointer to the source string to be appended.
 * @param size Total size of the destination buffer.
 * @return The total length of the string it tried to create.
 */
size_t core_strlcat(char *dest, const char *src, size_t size){

    int src_len = core_strlen(src);
    int dest_len =  core_strlen(dest)-1;
    size_t i = 0;


    if(src_len <= size-dest_len){

        return src_len;
    }
    while (src[i] != '\0' && (dest_len+i) < size)
    {
        dest[dest_len] = src[i];
        dest_len++;
        i++;
    }


    dest[dest_len+i] = '\0';

    return (dest_len+src_len);
    

}

/**
 * @brief Convert lowercase letter to uppercase.
 * 
 * If the argument is a lowercase letter, the toupper() function returns 
 * the corresponding uppercase letter. Otherwise, it returns the argument.
 * 
 * @param c The character to be converted (passed as an int).
 * @return The uppercase equivalent, or the original character if no 
 *         conversion was possible.
 */
int core_toupper(int c){
    if(c>='a' && c<='z')
        return (c-32);
    else
        return (c);
}

/**
 * @brief Convert uppercase letter to lowercase.
 * 
 * If the argument is an uppercase letter, the tolower() function returns 
 * the corresponding lowercase letter. Otherwise, it returns the argument.
 * 
 * @param c The character to be converted (passed as an int).
 * @return The lowercase equivalent, or the original character if no 
 *         conversion was possible.
 */
int core_tolower(int c){
     if(c>='A' && c<='Z')
        return (c+32);
    else
        return (c);
}


/**
 * @brief Locates the first occurrence of a character in a string.
 * 
 * The strchr() function finds the first occurrence of the character c 
 * (converted to a char) in the string pointed to by s. The terminating 
 * null character is considered part of the string.
 * 
 * @param s Pointer to the null-terminated string to be searched.
 * @param c The character to be located (passed as an int).
 * @return A pointer to the located character, or NULL if not found.
 */
char *core_strchr(const char *s, int c){

    int i = 0;

    while(s[i] != '\0'){
        if(s[i] == (char) c)
            return (char *)&s[i];
    i++;
    }

    if((char )c =='\0')
        return (char *)&s[i];

    return (NULL);
}

