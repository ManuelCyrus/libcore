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
            else if(format[i] == 'f'){
                core_putfloat(va_arg(arg,double));
            }
            else if(format[i] == '.'){
        
                if(format[i+1] >= '0' && format[i+1] <= '9')
                {   i++;
                    i++;
                    while(format[i] != '\0' && format[i] >= '0' && format[i]<='9')i++;
                    if(format[i] == 'f'){
                        core_putfloat(va_arg(arg,double),6);
                    }
                    else{
                    i--;
                    i--;
                        core_putchar(format[i]);
                    }
                }
                    
                     
            }else if(format[i] == 'u'){
                core_putnbr_unsigned(va_arg(arg,unsigned int));
            }
            else if(format[i] == 'x' || format[i] == 'X'){
                if(format[i]=='x')
                    core_putstr(core_str_hex(va_arg(arg,int),'x'));
                else
                    core_putstr(core_str_hex(va_arg(arg,int),'X'));

            }

            else if(format[i] == '%'){
                core_putchar('%');
            }
            else{

            core_putchar(format[i]);
            }


        }

        i++;
   }
return (i);

   va_end(arg);
}
