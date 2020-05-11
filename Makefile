NAME1=	checker

NAME2=	push_swap

all:	lib $(NAME1) $(NAME2)

lib:
	make re -C ./libft/


SRC1=	checker.c

SRC2=	push_swap.c

OBJ1=	$(SRC1:.c=.o)

OBJ2=	$(SRC2:.c=.o)

$(NAME1):
	gcc -Wall -Werror -Wextra -c $(SRC1)
	gcc -o $(NAME1) $(OBJ1) -L. ./libft/libft.a


$(NAME2):
	gcc -Wall -Werror -Wextra -c $(SRC2)
	gcc -o $(NAME2) $(OBJ2) -L. ./libft/libft.a

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re:	fclean all