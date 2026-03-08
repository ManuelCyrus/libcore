#include "../../include/core.h"



char *get_next_line(int fd){





    
}


static ssize_t read_file(int fd , char *buffer){
       char *mem;
       ssize_t bytes_read=0;

    if(fd < 0 || !buffer)
        return (-1);

        while (1)
        {
            bytes_read = read(fd,buffer,BUFFER_SIZE);
            
            if(bytes_read > 0)
                buffer[bytes_read] = '\0';
            mem = core_str_join(mem,buffer);
            
        

        }
        
    return (bytes_read);

}



