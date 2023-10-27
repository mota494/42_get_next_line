NAME = libftprintf.a
CC= cc
FLAGS= -Wall -Wextra -Werror
SRC= get_next_line.c get_next_line_utils.c
RM = rm -rf
OBJS=$(SRC:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -c $*.c -o $*.o

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all

exec:
	$(CC) $(SRC)

norm:
	norminette $(SRC) get_next_line.h