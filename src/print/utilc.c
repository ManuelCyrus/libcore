#include <stdio.h>
#include <unistd.h>

void core_putchar(char c){
    write(1,&c,1);
}

int core_strlen(char *str){

    int i = 0;
    while(str[i] != '\0'){
        i++;
    }

    return (i);
}

void core_putstr(char *str){

    write(1,&str,core_strlen(str));

}

int  core_atoi(char *str){

    long i = 0;
    long signal = 1;
    long nbr = 0;

    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;

    if(str[i] == '+' || str[i] == '-'){
        if(str[i] == '-'){
            signal = -1 ;
        }
        i++;
    }

    

    while(str[i] && str[i] >= '0' && str[i] <= '9'){
        nbr = nbr * 10 + (str[i] - '0');
        i++;
    }

    return (nbr*signal);
    
}


int main(void){

    printf("%d",core_atoi("100"));

}