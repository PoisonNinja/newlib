#ifndef _SYS_ERRNO_H
#define _SYS_ERRNO_H

#define errno __tls_errno
extern __thread int errno;

#endif
