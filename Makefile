NAME = dijkstra

SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = .obj

FILE =	create_dict.c \
		dict.c \
		ft_split.c \
		ft.c \
		functions.c \
		init_update.c \
		main.c \
		parser.c \
		solve.c \
		valid.c \

OBJ_DIR = .obj

SRC = $(addprefix $(SRC_DIR)/, $(FILE))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILE:.c=.o))
DEP = $(addprefix $(OBJ_DIR)/, $(FILE:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -I$(INC_DIR) -g3

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -g3

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
