# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME 	= 	Cub3d

CC 		=	gcc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror -g -gdwarf-4

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

PINK        = \033[1;38;2;255;105;180m
LIGHT_PINK  = \033[1;38;2;255;182;193m
HOT_PINK    = \033[1;38;2;255;20;147m
MAGENTA     = \033[1;35m
LIGHT_MAG   = \033[1;95m
PURPLE      = \033[1;38;2;128;0;128m
VIOLET      = \033[1;38;2;138;43;226m
LAVENDER    = \033[1;38;2;230;190;255m
ORCHID      = \033[1;38;2;218;112;214m
PLUM        = \033[1;38;2;221;160;221m

BROWN       = \033[1;38;2;101;67;33m
GREEN       = \033[1;92m
RED         = \033[1;91m
LIGHT_CYAN  = \033[1;96m
RESET       = \033[0m

# **************************************************************************** #
#                                   PATHS                                      #
# **************************************************************************** #

PATH_LIBFT 	= libft
LIB_LIBFT 	= libft/libft.a

PATH_MLX    =   mlx
LIB_MLX     =   mlx/libmlx.a

OBJS_DIR	=	objs

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRCS 		=  $(wildcard *.c) \
				$(wildcard srcs/*.c) \
				$(wildcard srcs/execute/*.c) \
				$(wildcard srcs/parsing/*.c)

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

INCLUDES	=	-Iinclude -I$(PATH_LIBFT) -I$(PATH_MLX)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(LIB_LIBFT) $(LIB_MLX) $(NAME)

$(LIB_LIBFT):
	@make -s -C $(PATH_LIBFT)

$(LIB_MLX):
	@make -s -C $(PATH_MLX) > /dev/null 2>&1 || (make -C $(PATH_MLX) && exit 1)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIB_LIBFT) $(LIB_MLX)
	@$(CC) $(CFLAGS) $(OBJS) \
		-L$(PATH_LIBFT) -lft \
		-L$(PATH_MLX) -lmlx \
		-lX11 -lXext \
		-o $(NAME)
		@printf "$(PLUM)✓ $(NAME) compiled successfully!$(RESET)\n"

# **************************************************************************** #
#                                   CLEANUP                                    #
# **************************************************************************** #

clean:
	@$(RM) $(OBJS_DIR)
	@make -s -C $(PATH_LIBFT) clean
	@make -s -C $(PATH_MLX) clean > /dev/null 2>&1 || (make -C $(PATH_MLX) clean && exit 1)
	@printf "$(ORCHID)Object files cleaned!$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(PATH_LIBFT) fclean > /dev/null 2>&1 || (make -C $(PATH_MLX) clean && exit 1)
	@printf "$(LAVENDER)Full cleanup done!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re