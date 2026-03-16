#ifndef CORE_FILES
#define CORE_FILES

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif


#if BUFFER_SIZE < 0
#undef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif


char *get_next_line(int fd);
void readlines(int fd);



#endif