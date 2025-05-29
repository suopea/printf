NAME = libftprintf.a
SRC = ft_printf.c print_base.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^	

%.o: %.c
	cc $(FLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

rec: re clean

re: fclean all

.PHONY: all re fclean clean rec
.SECONDARY: $(OBJ)
