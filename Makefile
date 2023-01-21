NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = -L lib/libft -lft

SRCPATH = src/
SRC = pipex.c \
	pipex_utils.c \
	errors.c \
	free.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(MAKE) --no-print-directory -C lib/libft
	echo "\033[36mMaking pipex\033[0m"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -g
	echo "\033[32mDone\033[0m"

%.o : $(SRCPATH)%.c
	$(CC) $(CFLAGS) -c $^ -g

bonus : all

clean :
	$(MAKE) --no-print-directory fclean -C lib/libft
	echo "\033[35mCleaning pipex's objects ...\033[0m"
	rm -f $(OBJ)
	echo "\033[32mDone\033[0m"

fclean :
	make clean
	echo "\033[35mCleaning pipex ...\033[0m"
	rm -f $(NAME)
	echo "\033[32mDone\033[0m"

re : fclean
	make all

.PHONY : all clean fclean re bonus
.SILENT :