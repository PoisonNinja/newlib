#ifndef _SYS_STAT_H
#define _SYS_STAT_H

#include <sys/types.h>

int mknod(const char *pathname, mode_t mode, dev_t dev);

#endif