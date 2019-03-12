#ifndef _POLL_H
#define _POLL_H

#define POLLERR (1 << 0)
#define POLLHUP (1 << 1)
#define POLLNVAL (1 << 2)

#define POLLIN (1 << 3)
#define POLLRDNORM (1 << 4)
#define POLLRDBAND (1 << 5)
#define POLLPRI (1 << 6)
#define POLLOUT (1 << 7)
#define POLLWRNORM (1 << 8)
#define POLLWRBAND (1 << 9)

#define POLL__ONLY_REVENTS (POLLERR | POLLHUP | POLLNVAL)

struct pollfd
{
    int fd;
    short events;
    short revents;
};

typedef unsigned int nfds_t;

int poll(struct pollfd *fds, nfds_t nfds, int timeout);

#endif