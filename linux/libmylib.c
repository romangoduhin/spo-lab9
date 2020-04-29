#include <dirent.h> 
#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int isdir(const char *path)
{
    struct stat statbuf;
    stat(path, &statbuf);
    return S_ISDIR(statbuf.st_mode);
}

void addPostfixToFilesInDirectory(const char* directory, const char* postfix)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(directory);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            char buf[1000]="";
            strcat(buf, directory);
            strcat(buf, "/");
            strcat(buf, dir->d_name);
            if(!isdir(buf))
            {
                char oldname[1000]="";
                strcpy(oldname, buf);
                char* pos=strpbrk(buf, ".");
                if(pos!=NULL)
                {
                    char ended[1000]="";
                    strcat(ended, pos);
                    memcpy(pos, postfix, strlen(postfix));
                    strcat(pos, ended);
                    rename(oldname, buf);
                }   
            }
            else if(strcmp(dir->d_name, ".")!=0&&strcmp(dir->d_name, "..")!=0)
                addPostfixToFilesInDirectory(buf, postfix);
        }
    closedir(d);
  }
}




