#ifndef CORE_STR_H
# define CORE_STR_H

#include <stdlib.h>

// string
void core_putchar(char c);
void core_putstr(char *str);
char *core_firstworld(char *str,char delim);
int core_search_delim(char *str, char delim);
int core_is_alphabet(char c);
char *core_str_join(char *s1, char *s2);
int core_strlen(char *str);




int core_isdigit(char c);
int core_isalnum(char c);
int core_isascii(char c);
int core_isprint(char c);
void *core_memset(void *s, int c, size_t n);
void core_bzero(void *s, size_t n);



#endif