CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -o3 -g3
LIBFT		= -L./libft -lft
INCLUDES	= -I libft/include
SRCS_PATH	= ./

NAME 		= push_swap

SRC 	=	main.c \
			utils.c \
			test.c \
			push.c \
			swap.c \
			rotate.c \
			r_rotate.c

SRCS 	= 	$(addprefix $(SRCS_PATH)/,$(SRC))
OBJS	=	$(SRCS:.c=.o)

_BLUE	=	\e[34m
_PURPLE	=	\e[35m
_CYAN	=	\e[36m
_END	=	\e[0m

%.o: %.c
			@printf "PUSH_SWAP object :		$(_BLUE)%-33.33s\r$(_END)\n" $@
			@${CC} ${CFLAGS} $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS) libft/libft.a
			@printf "libft			[$(_BLUE)✓$(_END)]\n"
			@printf "push_swap objects	[$(_BLUE)✓$(_END)]\n"
			@gcc $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) -o $(NAME)
			@printf "push_swap		[$(_BLUE)✓$(_END)]\n"

libft/libft.a : 
			@$(MAKE) -C ./libft

all : 		$(NAME)

re:			fclean
			$(MAKE) $(NAME)

clean :
			@rm -rf $(OBJS)
			@$(MAKE) clean -C ./libft
			@printf "$(_PURPLE)FDF object	deleted$(_END)\n"

fclean :	clean
			@$(MAKE) fclean -C ./libft
			@rm -rf $(NAME)
			@printf "$(_PURPLE)push_swap		deleted$(_END)\n"

leaks :		all
			leaks --atExit -- ./$(NAME) ./test_map/42.fdf
PHONY : re all clean fclean