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
	@make -s -C $(PATH_MLX)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIB_LIBFT) $(LIB_MLX)
	@$(CC) $(CFLAGS) $(OBJS) \
		-L$(PATH_LIBFT) -lft \
		-L$(PATH_MLX) -lmlx \
		-lX11 -lXext \
		-o $(NAME)
		@printf "$(GREEN)$(NAME) compiled successfully!$(RESET)\n"

# **************************************************************************** #
#                                   CLEANUP                                    #
# **************************************************************************** #

clean:
	@$(RM) $(OBJS_DIR)
	@make -s -C $(PATH_LIBFT) clean
	@make -s -C $(PATH_MLX) clean
	@printf "$(RED)Object files cleaned!$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(PATH_LIBFT) fclean
	@printf "$(LIGHT_CYAN)Full cleanup done!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re