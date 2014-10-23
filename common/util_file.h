#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <vector>
#include <sstream>

void get_file_in_dir(const char* dir,vector<string>& all_file)
{
    DIR* pdir = opendir(dir);
    if(pdir == NULL)return;
    struct dirent* ent = NULL;
    while(NULL != (ent = readdir(pdir)))
    {
        if(ent->d_type == 8)
        {
            all_file.push_back(ent->d_name);    
        }
    }
    closedir(pdir);
}

std::vector<std::string> &split(std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


// std::vector<std::string> split(const std::string &s, char delim) {
//     std::vector<std::string> elems;
//     split(s, delim, elems);
//     return elems;
// }
