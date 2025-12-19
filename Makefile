NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRCS = srcs/main.c \
    srcs/utils/stack_utils.c \
    srcs/utils/parse.c \
    srcs/utils/error.c \
    srcs/operations/swap.c \
    srcs/operations/push.c \
    srcs/operations/rotate.c \
    srcs/operations/reverse_rotate.c \
    srcs/sort/sort_three.c \
    srcs/sort/sort_utils.c \
    srcs/sort/sort_4_5.c \
    srcs/sort/assign_indexes.c \
    srcs/sort/chunk_sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)  

fclean: clean
	rm -f $(NAME)  

re: fclean all

.PHONY: all clean fclean re