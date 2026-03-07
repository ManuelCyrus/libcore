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
int core_strlen(const char *str);




int core_isdigit(char c);
int core_isalnum(char c);
int core_isascii(char c);
int core_isprint(char c);
void *core_memset(void *s, int c, size_t n);
void core_bzero(void *s, size_t n);
void *core_memcpy(void *dest, const void *src, size_t n);
void *core_memmove(void *dest, const void *src, size_t n);
size_t core_strlcpy(char *dest, const char *src, size_t size);
size_t core_strlcat(char *dest, const char *src, size_t size);
int core_tolower(int c);
int core_toupper(int c);
char *core_strchr(const char *s, int c);



#endif