#ifndef  CORE_UTILS
#define CORE_UTILS

// numbers and math
int core_atoi(char *str);
char *core_itoa(int nbr);
void core_putnbr(int nbr);
void core_putfloat(double nbr,...);
int core_is_prime(int nbr);
int core_is_digit(char c);
int core_number_length(int nbr);
void core_putnbr_unsigned(unsigned int number);
//exponetiontion

int core_pow(int base, int expo);
int  core_abs(int x);
float core_fabs(int x);
double core_fmod(int a,int b);





//
char *core_str_hex(unsigned int nbr,char c);
long core_nbr_octal(unsigned int nbr);





#endif