#include <sys/ioctl.h>
#include <termios.h>
#include <errno.h>

int tcgetattr(int fd, struct termios *termios_p)
{
    return ioctl(fd, TCGETS, termios_p);
}

int tcsetattr(int fd, int optional_actions,
              const struct termios *termios_p)
{
    unsigned long cmd = 0;
    switch (optional_actions)
    {
    case TCSANOW:
        cmd = TCSETS;
        break;
    case TCSADRAIN:
        cmd = TCSETSW;
        break;
    case TCSAFLUSH:
        cmd = TCSETSF;
        break;
    default:
        return -EINVAL;
    }
    return ioctl(fd, cmd, termios_p);
}

int tcsendbreak(int fd, int duration)
{
    return ioctl(fd, TCSBRK, (char *)duration);
}

int tcdrain(int fd)
{
    return -ENOSYS;
}

int tcflush(int fd, int queue_selector)
{
    return ioctl(fd, TCFLSH, (char *)queue_selector);
}

int tcflow(int fd, int action)
{
    return ioctl(fd, TCXONC, (char *)action);
}

void cfmakeraw(struct termios *termios_p)
{
    termios_p->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
    termios_p->c_oflag &= ~OPOST;
    termios_p->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    termios_p->c_cflag &= ~(CSIZE | PARENB);
    termios_p->c_cflag |= CS8;
    termios_p->c_cc[VMIN] = 1; /* read returns when one char is available.  */
    termios_p->c_cc[VTIME] = 0;
}

speed_t cfgetispeed(const struct termios *termios_p)
{
    return termios_p->c_ispeed;
}

speed_t cfgetospeed(const struct termios *termios_p)
{
    return termios_p->c_ospeed;
}

int cfsetispeed(struct termios *termios_p, speed_t speed)
{
    termios_p->c_ispeed = speed;
}

int cfsetospeed(struct termios *termios_p, speed_t speed)
{
    termios_p->c_ospeed = speed;
}

int cfsetspeed(struct termios *termios_p, speed_t speed)
{
    termios_p->c_ispeed = speed;
    termios_p->c_ospeed = speed;
}
