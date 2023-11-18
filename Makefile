NAME = push_swap

SRC_DIR = srcs
OBJ_DIR = obj

SRC = check.c moves.c moves2.c push_swap.c sort.c sort2.c utils.c utils2.c tests.c
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft/includes
LDFLAGS = -Llibft -lft

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
