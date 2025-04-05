NAME = so_long
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Werror -Wextra -g 
CC = cc

SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	cd $(LIBFT_DIR) && make clean
	rm -f $(OBJS)

fclean:
	cd $(LIBFT_DIR) && make fclean
	rm -f $(NAME)

re: fclean all