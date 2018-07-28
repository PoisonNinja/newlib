#ifndef _SYS_SYSMACROS_H
#define _SYS_SYSMACROS_H

#include <sys/types.h>

static inline dev_t makedev(unsigned int maj, unsigned int min)
{
    return ((maj & 0xFF) << 8) | ((min & 0xFF) << 0);
}

static inline unsigned int major(dev_t dev)
{
    return (dev >> 8) & 0xFF;
}

static inline unsigned int minor(dev_t dev)
{
    return (dev >> 0) & 0xFF;
}

#endif
