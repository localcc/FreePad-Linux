include config.mk

SRC = freepad.c wav_file.h
OBJ = ${SRC:.c=.o}

all: options freepad

options:
	@echo freepad build options:
	@echo "CFLAGS	= ${CFLAGS}"
	@echo "LDFLAGS	= ${LDFLAGS}"
	@echo "CC	= ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.h $@

freepad: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}
