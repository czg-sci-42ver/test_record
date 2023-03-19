#
# makefile
#
CFLAGS = -m64 -std=c99
SRCS = $(wildcard *.c)
SRCS := $(filter-out float-half-test.c main.c, $(SRCS))
LIBFILE = ../lib/random.c

all:
	gcc $(CFLAGS) $(SRCS) $(LIBFILE) -g3 -o main


test:
	./main

.PHONY : clean
clean:
	find . -type f -executable -print0 | xargs -0 rm -f --

# vim:ft=make
#
