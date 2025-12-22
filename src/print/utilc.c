
void print_char(char c){
    write(1,&c,1);
}

int print_lengh(char *str){

    int i = 0;
    while(str[i] != '\0'){
        i++;
    }

    return i;
}

void print_str(char *str){

    write(1,&str,print_lengh(str));

}
