CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g
EXEC = main
SRC = main.c map.c player.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)
main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf *.o *~
mrproper: clean
	rm -rf $(EXEC)
