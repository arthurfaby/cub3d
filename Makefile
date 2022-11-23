NAME			= cub3d

SRCS			= \
				main.c \
				srcs/minimap.c \
				srcs/window.c \
				srcs/game.c \
				srcs/drawing.c \
				srcs/hook.c \
				srcs/interaction.c \
				\

OBJS			= $(SRCS:.c=.o)

INCSDIR			= includes

MLX				= minilibx
LIBFT			= libft

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -L$(MLX) -lmlx -L$(LIBFT) -lft -lXext -lX11 -lm -g
INCS			= -I$(INCSDIR) -I$(LIBFT) -I$(MLX)

RM				= rm -f

.c.o:
				$(CC) $(INCS) $(CFLAGS) -c $< -o $(<:.c=.o) 

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C $(MLX)
				make -C $(LIBFT)
				$(CC) $(OBJS) -o $@ $(CFLAGS)

clean:
				make clean -C $(MLX)
				make clean -C $(LIBFT)
				$(RM) $(OBJS)

fclean:			clean
				make fclean -C $(LIBFT)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
