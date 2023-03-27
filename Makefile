CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -o3 -g
LIBFT		= -L./libft -lft
INCLUDES	= -I libft/include/ -I includes/
SRCS_PATH	= ./src

NAME		= pipex

SRC		=	main.c \
			utils.c \
			pipex_split.c

SRCS 	= 	$(addprefix $(SRCS_PATH)/,$(SRC))
OBJS	=	$(SRCS:.c=.o)

_BLUE	=	\e[34m
_PURPLE	=	\e[35m
_CYAN	=	\e[36m
_END	=	\e[0m

%.o: %.c
			@printf "PIPEX object :		$(_BLUE)%-33.33s\r$(_END)\n" $@
			@${CC} ${CFLAGS} $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS) libft/libft.a
			@printf "libft			[$(_BLUE)✓$(_END)]\n"
			@printf "pipex objects	[$(_BLUE)✓$(_END)]\n"
			@gcc $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) -o $(NAME)
			@printf "pipex		[$(_BLUE)✓$(_END)]\n"

libft/libft.a : 
			@$(MAKE) -C ./libft

all : 		$(NAME)

re:			fclean
			$(MAKE) $(NAME)

clean :
			@rm -rf $(OBJS)
			@$(MAKE) clean -C ./libft
			@printf "$(_PURPLE)PIPEX object	deleted$(_END)\n"

fclean :	clean
			@$(MAKE) fclean -C ./libft
			@rm -rf $(NAME)
			@printf "$(_PURPLE)pipex		deleted$(_END)\n"

leaks :		all
			leaks --atExit -- ./$(NAME)
PHONY : re all clean fclean