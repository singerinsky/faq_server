#include <iostream>
#include "stdio.h"
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>


int main()
{
    pid_t pid = getpid();
    printf("%d",pid);
    FILE* file = fopen("pid.data","w+b"); 
    if(file == NULL)
    {
        perror("error open pid file"); 
        return 0;
    }

    int last_pid =0;
    int read_size = fscanf(file,"%d",&last_pid);
    if(last_pid == 0)
    {
        printf("process is not running"); 
        fprintf(file,"%d",pid);
        return 1;
    }

    char process_buffer[100];
    sprintf(process_buffer,"/proc/%d",last_pid);
    DIR* dir = opendir(process_buffer);
    //process is running 
    if(dir == NULL)
    {
        rewind(file);
        fprintf(file,"%d",pid);
    }else
    {
        closedir(dir); 
    }

    fclose(file);
    char write_str[100];
    //memset(write_str,0,100);
    

    return 1;
}
