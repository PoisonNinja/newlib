#ifndef _SYS_DIRENT_H
#define _SYS_DIRENT_H

#include <stdint.h>

typedef struct dirent
{
    uint32_t d_ino;
    char d_name[256];
} dirent;

typedef struct _dirdesc
{
    int dd_fd;
    long dd_loc;
    long dd_size;
    char *dd_buf;
    int dd_len;
    long dd_seek;
} DIR;

#define __dirfd(dp) ((dp)->dd_fd)

DIR *opendir(const char *);
struct dirent *readdir(DIR *);
int readdir_r(DIR *__restrict, struct dirent *__restrict,
              struct dirent **__restrict);
void rewinddir(DIR *);
int closedir(DIR *);

#endif