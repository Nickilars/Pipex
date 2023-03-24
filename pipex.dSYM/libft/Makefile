CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g -o1

SRC_PATH	= ./src/

SORT_PATH	=./src/tri/

LIST_PATH	= ./src/list/simpl_list/

DLIST_PATH	= ./src/list/doubl_list/

CLIST_PATH	=./src/list/circular_list/

GNL_SRC_PATH	= ./src/gnl/

PRINTF_SRC_PATH	= ./src/ft_printf/

SRC	= ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_atoi.c \
			ft_strncmp.c \
			ft_memcmp.c \
			ft_itoa.c \
			ft_strdup.c \
			ft_strchr.c \
			ft_nbrlen_d.c \
			ft_nbrlen_exa.c \
			ft_strrchr.c \
			ft_strlen.c \
			ft_islower.c \
			ft_isupper.c \
			ft_free_2da.c \
			ft_free_arrays.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_split.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_substr.c \
			ft_strnstr.c \
			ft_bzero.c \
			ft_nbrlen_b.c \
			ft_itob.c \
			ft_btoi.c \
			ft_atob.c \
			ft_power.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_calloc.c \
			ft_memset.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_striteri.c \
			ft_free.c \
			ft_swap.c \
			ft_exit.c

SORT_SRC		= bubblesort.c \
				quicksort.c

SRC_SLIST	= ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c

SRC_DLIST	= ft_dlst_addback.c \
				ft_dlst_addfront.c \
				ft_dlst_clear.c \
				ft_dlst_new.c \
				ft_dlst_newcontent.c \
				ft_pop_front.c \
				ft_pop_back.c \
				ft_dlst_add.c \
				ft_dlst_delone.c

SRCS_GNL	= get_next_line.c \
				get_next_line_utils.c

SRCS_PRINTF	= ft_printf.c \
				ft_print_c.c \
				ft_print_d.c \
				ft_print_hex.c \
				ft_print_p.c \
				ft_print_s.c \
				ft_print_u.c

SRCS	= $(addprefix $(SRC_PATH)/,$(SRC)) $(addprefix $(LIST_PATH)/,$(SRC_SLIST)) $(addprefix $(DLIST_PATH)/,$(SRC_DLIST)) $(addprefix $(GNL_SRC_PATH)/,$(SRCS_GNL)) $(addprefix $(PRINTF_SRC_PATH)/,$(SRCS_PRINTF)) $(addprefix $(SORT_PATH)/,$(SORT_SRC))

OBJS	= $(SRCS:.c=.o)

%.o: %.c
# @printf "Libft object :		$(_BLUE)%-33.33s\r$(_END)\n" $@
			@${CC} ${CFLAGS} -c $< -o $@


NAME	= libft.a

RM		= rm -f

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

all :	$(NAME)

$(NAME) : $(OBJS)
		@ar -rs $(NAME) $(OBJS)

re : fclean $(NAME)

clean :
		$(RM) *.o $(SRC_PATH)*.o $(GNL_SRC_FOLDER)*.o $(PRINTF_SRC_FOLDER)*.o

fclean : clean
		$(RM) $(NAME)

.PHONY: all re clean fclean