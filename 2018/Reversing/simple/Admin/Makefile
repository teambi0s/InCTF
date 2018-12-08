cc = gcc
cflags = -nostdlib -Os 

all: simple

libc.o: libc.S libc.c
	$(cc) $(cflags) -r -o libc.o libc.S libc.c


simple: simple.c libc.o
	$(cc) $(cflags) -static -o simple -no-pie -lc --entry main simple.c libc.o
