EXEC = dijkstra_solver.exe
CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q *.o 2>nul || echo Nothing to clean

fclean: clean
	del /Q $(EXEC) 2>nul || echo Nothing to remove

re: fclean all

.PHONY: all clean fclean re