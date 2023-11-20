#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#·                                                                                           ·#
#·                                        COLORS                                             ·#
#·                                                                                           ·#
#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#

RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#·                                                                                           ·#
#·                                       COMMANDS                                            ·#
#·                                                                                           ·#
#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#

CC = cc
RM = rm -rf
AR = ar -rcs

#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#·                                                                                           ·#
#·                                         FLAGS                                             ·#
#·                                                                                           ·#
#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#

CFLAGS	= -Wall -Wextra -Werror
MK		= --no-print-directory

#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#·                                                                                           ·#
#·                                        FOLDERS                                            ·#
#·                                                                                           ·#
#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#

DEPS			= includes 
SRCS			= .
_SUBFOLDERS		= checks convert memory print str get_next_line linked_lists
VPATH			= srcs $(addprefix $(SRCS)/ft_, $(_SUBFOLDERS))
OBJ_DIR			= bin

#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#·                                                                                           ·#
#·                                        FILES                                              ·#
#·                                                                                           ·#
#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#


NAME	= 	libft.a

_FILES += 	isalnum isalpha isascii isdigit isprint

_FILES += 	atoi itoa tolower toupper

_FILES += 	bzero calloc memchr memcmp memcpy memmove memset

_FILES += 	print_char print_decimal print_hexadecimal print_percent print_pointer print_string \
			print_unsigned_decimal printf putchar_fd putendl_fd putnbr_fd putstr_fd

_FILES += 	split strchr strcmp strdup striteri strjoin strlcat strlcpy strlen strmapi strncmp strnstr \
			strrchr strtrim substr

_FILES +=	get_next_line get_next_line_utils

_FILES += lst_add_back lst_add_front lst_clear lst_delone lst_iter lst_last lst_map lst_new lst_size

OBJS			= $(_FILES:%=ft_%.o)
TARGET			= $(addprefix $(OBJ_DIR)/, $(OBJS))

#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#·                                                                                           ·#
#·                                         RULES                                             ·#
#·                                                                                           ·#
#· · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#


all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	$(AR) $(NAME) $(TARGET)
	
$(OBJ_DIR)/%.o : $(SRCS)/%.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean:	
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

norm:
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.h FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R CheckDefine $(shell find . -type f -name "*.h")
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.c FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R checkForbiddenSourceHeader $(shell find . -type f -name "*.c")

.SILENT: