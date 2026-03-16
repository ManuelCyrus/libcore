#include "../../include/core.h"



static char  *read_file(int fd){
       char *mem = core_strdup("");
        char *buffer = malloc(BUFFER_SIZE + 1);
       ssize_t bytes_read = 0;
       char *temp;

    if(fd < 0 || !buffer)
    {
        return NULL;
    }
        while(1)
        {
            bytes_read = read(fd,buffer,BUFFER_SIZE);
            
            if(bytes_read > 0)
            {
                buffer[bytes_read] = '\0';
                temp=mem;
                mem = core_str_join(temp,buffer);
                free(temp);
            }
            else{
                break;
            }
            
        }
        
        free(buffer);
    return (mem);

}





static char *get_line(char *str) {
    int i = 0;
    if (!str[0]) return NULL;

    while (str[i] && str[i] != '\n')
        i++;

    int has_nl = (str[i] == '\n');
    char *new = malloc(i + has_nl + 1);
    if (!new) return NULL;

    int k = -1;
    while (++k < i)
        new[k] = str[k];
    
    if (has_nl)
        new[k++] = '\n';
    new[k] = '\0';
    return (new);
}

static char *save_remaining(char *str) {
    int i = 0;

    while (str[i] && str[i] != '\n')
        i++;

    if (!str[i] || !str[i + 1]) {
        return (NULL);
    }

    return core_strdup(str + i + 1);
}

/**
 * @brief Reads a single line from a given file descriptor.
 * 
 * This function reads from 'fd' until a newline character ('\n') or 
 * the end of file (EOF) is reached. It uses a static variable to 
 * preserve the remaining buffer content across successive calls.
 * 
 * @param fd The file descriptor to read from.
 * @return A pointer to the string containing the line (including the '\n'), 
 *         or NULL if the end of file is reached or an error occurs.
 */
char *get_next_line(int fd) {
    static char *content = NULL; 
    char *line;
    char *temp_content;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if (!content)
        content = read_file(fd);

    if (!content || *content == '\0')
    {
        free(content);
        content = NULL;
        return (NULL);
    }

    line = get_line(content);
    
    temp_content = content;
    content = save_remaining(temp_content);
    free(temp_content);

    return (line);
}

