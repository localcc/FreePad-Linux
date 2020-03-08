X11LIB 		= /usr/X11R6/lib
LIBS		= -L${X11LIB} -lX11 -lpulse-simple -lpthread
CFLAGS		= -std=c99 -Wall -Wno-deprecated-declarations -Os -lX11
LDFLAGS		= ${LIBS}
CC		= gcc
