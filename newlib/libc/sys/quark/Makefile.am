AUTOMAKE_OPTIONS = cygnus
INCLUDES = -I$(srcdir)/include $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)
AM_CCASFLAGS = $(INCLUDES)

noinst_LIBRARIES = lib.a

GENERAL_SOURCES = \
	errno.c \
	malloc.c \
	syscalls.c \
	syscall.S \
	termios.c

lib_a_SOURCES = $(GENERAL_SOURCES)
lib_a_CCASFLAGS = $(AM_CCASFLAGS)
lib_a_CFLAGS = $(AM_CFLAGS)

all: crt0.o

ACLOCAL_AMFLAGS = -I ../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
