#ifndef _SYS_POLL_H
#define _SYS_POLL_H

#define POLLIN 1    /* Set if data to read. */
#define POLLPRI 2   /* Set if urgent data to read. */
#define POLLOUT 4   /* Set if writing data wouldn't block. */
#define POLLERR 8   /* An error occured. */
#define POLLHUP 16  /* Shutdown or close happened. */
#define POLLNVAL 32 /* Invalid file descriptor. */

#define NPOLLFILE 64 /* Number of canonical fd's in one call to poll(). */

/* The following values are defined by XPG4. */
#define POLLRDNORM POLLIN
#define POLLRDBAND POLLPRI
#define POLLWRNORM POLLOUT
#define POLLWRBAND POLLOUT

struct pollfd
{
    int fd;
    short events;
    short revents;
};

typedef unsigned int nfds_t;

int poll(struct pollfd *fds, nfds_t nfds, int timeout);

#endif