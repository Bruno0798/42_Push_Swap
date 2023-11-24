NAME = push_swap

SRC_DIR = srcs
OBJ_DIR = obj

SRC = tests.c auxiliary_functions.c input_validation.c moves_calculations.c moves_calculations2.c moves_calculations3.c push_swap.c sorting.c sorting2.c sorting3.c stack_information.c stack_management.c stack_manipulation.c stack_manipulation2.c
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft/includes
LDFLAGS = -Llibft -lft

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.SILENT: