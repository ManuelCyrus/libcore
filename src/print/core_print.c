#include "../../include/core.h"

/*!
 * @brief Prints a formatted message to the standard output.
 *
 * This function receives a format string and a variable
 * list of arguments.
 *
 * @param restrict format Format string.
 * @param ... Variable arguments used by the format string.
 *
 * @return Number of characters printed, or a negative value on error.
 */
int print(const char * restrict format, ...)
{
   va_list arg;
    int i = 0;
   va_start(arg,format);


   while(format[i] != '\0'){

        if(format[i] == '%'){
            i++;
            if(format[i]=='c'){
                core_putchar(va_arg(arg,int));
            }
            else if(format[i]== 's'){
                core_putstr(va_arg(arg,char *));
            }
            else if(format[i] == 'd' || format[i] == 'i'){
                core_putnbr(va_arg(arg,int));
            }
        }
        else{
             
        core_putchar(format[i]);
        }

        i++;
   }
return (i);

   va_end(arg);
}
