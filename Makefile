NAME			= cub3d

SRCS			= \
				main.c \
				srcs/game.c \
				srcs/parsing.c \
				srcs/parse_elements.c \
				srcs/parse_map.c \
				srcs/error.c \
				srcs/check_error_element.c \
				srcs/check_texture.c \
				srcs/check_color.c \
				srcs/check_map.c \
				srcs/check_map_utils.c \
				srcs/window.c \
				srcs/drawing.c \
				srcs/hook.c \
				srcs/utils.c \
				srcs/raycast.c \
				srcs/ray_no.c \
				srcs/ray_ne.c \
				srcs/ray_so.c \
				srcs/ray_se.c \
				\

SRCS_BONUS		= \
				main_bonus.c \
				bonus_srcs/parsing_bonus.c \
				bonus_srcs/parse_elements_bonus.c \
				bonus_srcs/parse_map_bonus.c \
				bonus_srcs/error_bonus.c \
				bonus_srcs/check_error_element_bonus.c \
				bonus_srcs/check_texture_bonus.c \
				bonus_srcs/check_color_bonus.c \
				bonus_srcs/check_map_bonus.c \
				bonus_srcs/check_map_utils_bonus.c \
				bonus_srcs/window_bonus.c \
				bonus_srcs/game_bonus.c \
				bonus_srcs/minimap_bonus.c \
				bonus_srcs/interaction_bonus.c \
				bonus_srcs/drawing_bonus.c \
				bonus_srcs/hook_bonus.c \
				bonus_srcs/utils_bonus.c \
				bonus_srcs/raycast_bonus.c \
				bonus_srcs/ray_no_bonus.c \
				bonus_srcs/ray_ne_bonus.c \
				bonus_srcs/ray_so_bonus.c \
				bonus_srcs/ray_se_bonus.c \
				\

INCSDIR			= includes
INCSDIR_BONUS	= includes_bonus

MLX				= minilibx
LIBFT			= libft

CC				= clang
CFLAGS			= -Wall -Werror -Wextra 
LIBS			= -L$(MLX) -lmlx -L$(LIBFT) -lft -lXext -lX11 -lm -g
INCS			= -I$(INCSDIR) -I$(LIBFT) -I$(MLX)
INCS_BONUS		= -I$(INCSDIR_BONUS) -I$(LIBFT) -I$(MLX)

RM				= rm -f

ifdef BONUS
	SRCS = $(SRCS_BONUS)
	INCS = $(INCS_BONUS)
endif

OBJS			= $(SRCS:.c=.o)
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

.c.o:
				$(CC) $(INCS) $(CFLAGS) -c $< -o $(<:.c=.o) 

all:			$(NAME)

bonus:
				make BONUS=1

$(NAME):		$(OBJS)
				make -C $(MLX)
				make -C $(LIBFT)
				$(CC) $(OBJS) -o $@ $(INCS) $(CFLAGS) $(LIBS)

clean:
				make clean -C $(MLX)
				make clean -C $(LIBFT)
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				make fclean -C $(LIBFT)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
