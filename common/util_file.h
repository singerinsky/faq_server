#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <vector>

void get_file_in_dir(const char* dir,vector<string>& all_file)
{
    DIR* pdir = opendir(dir);
    if(pdir == NULL)return;
    struct dirent* ent = NULL;
    while(NULL != (ent = readdir(pdir)))
    {
        string fullpath = 
    }

}
