
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -fno-stack-protector

all: my_program

my_program: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: my_program
	./my_program

clean:
	rm -f *.o my_program

.PHONY: all clean run
