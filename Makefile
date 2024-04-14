CC	=	gcc
CFLAGS	=	-Wall	-Wextra	-g

SOURCES	=	main.c	ip_maths.c	binary_ops.c
HEADERS	=	ip_maths.h	binary_ops.h
OBJECTS	=	$(SOURCES:.c=.o)
EXECUTABLE	=	main

$(EXECUTABLE):	$(OBJECTS)
	$(CC)	$(CFLAGS)	$(OBJECTS)	-o	$(EXECUTABLE)

main.o:	main.c	ip_maths.h	binary_ops.h
	$(CC)	$(CFLAGS)	-c	main.c

ip_maths.o:	ip_maths.c	ip_maths.h
	$(CC)	$(CFLAGS)	-c	ip_maths.c

binary_ops.o:	binary_ops.c	binary_ops.h
	$(CC)	$(CFLAGS)	-c	binary_ops.c

clean:
		rm	-f	$(EXECUTABLE)	$(OBJECTS)
