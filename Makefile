NAME = so_long
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
CC = cc

SRCS = main.c utils.c paths.c parc.c
OBJS = $(SRCS:.c=.o)
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit
all: $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) $(MLX) -lft -o $(NAME)

clean:
	cd $(LIBFT_DIR) && make clean
	rm -f $(OBJS)

fclean:
	cd $(LIBFT_DIR) && make fclean
	rm -f $(NAME) $(OBJS)

re: fclean all