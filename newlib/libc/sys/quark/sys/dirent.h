#ifndef _SYS_DIRENT_H
#define _SYS_DIRENT_H

#include <stdint.h>

typedef struct dirent
{
    uint32_t d_ino;
    char d_name[256];
} dirent;

typedef struct DIR
{
    int fd;
} DIR;

DIR *opendir(const char *dirname);
int closedir(DIR *dir);
struct dirent *readdir(DIR *dirp);

#endif