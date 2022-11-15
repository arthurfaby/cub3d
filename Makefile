NAME			= cub3d

SRCS			= \
				main.c
				\

OBJS			= $(SRCS:.c=.o)

INCSDIR			= includes

CC				= clang
CFLAGS			= -Wall -Werror -Wextra -g -I$(INCSDIR)
RM				= rm -rf

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

all:			$(NAME)

$(NAME):		$(OBJS)
#				make -C libft
				$(CC) $(OBJS) -o $@ $(CFLAGS)

clean:
#				make clean -C libft
				$(RM) $(OBJS)

fclean:			clean
#				make fclean -C libft
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
