#include <iostream>
#include "stdio.h"
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>


int check_process()
{
    pid_t pid = getpid();
    printf("%d",pid);
    FILE* file = fopen("pid.data","w+b"); 
    if(file == NULL)
    {
        perror("error open pid lock file!"); 
        return 0;
    }

    int last_pid =0;
    int read_size = fscanf(file,"%d",&last_pid);
    if(last_pid == 0)
    {
        printf("process is not running"); 
        fprintf(file,"%d",pid);
        return 0;
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
        return last_pid;
    }

    fclose(file);
    char write_str[100];
    //memset(write_str,0,100);
    

    return 0;
}

int main()
{
    int pid = check_process();
    if(pid == 0)
    {
        printf("process is not running ,you can run this process");
    }
    else
    {
        printf("process is running ,can't run this process"); 
    }
    return 1;
}
