CC = gcc
CFLAGS = -Wall -g

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

NAME = Simulator

program: $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(NAME)