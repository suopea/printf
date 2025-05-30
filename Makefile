NAME = libftprintf.a
SRC = ft_printf.c print_base.c
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $@ $(OBJ)

$(LIBFT):
	make -C libft
	make -C libft clean

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
