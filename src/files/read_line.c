#include "../../include/core.h"

/**
 * @brief Reads all lines from a file descriptor and processes them.
 * 
 * This function iteratively calls get_next_line() until the end of the file 
 * is reached. It serves as a wrapper to handle the complete content of 
 * the provided 'fd', ensuring proper resource management for each line.
 * 
 * @param fd The file descriptor to read from.
 * @return void
 */
void readlines(int fd){

    char buffer[BUFFER_SIZE+1];
    ssize_t bytes = 0;

    while((bytes = read(fd,buffer,BUFFER_SIZE+1))){

    if(bytes < 0)
        return;
    else{
        buffer[bytes] = '\0';
    }
    
    core_putstr(buffer);

    }


}