CC = gcc
CFLAGS = -Wall -Wextra

all: my_program

my_program: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: my_program
	./my_program

clean:
	rm -f *.o my_program

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

.PHONY: all clean run