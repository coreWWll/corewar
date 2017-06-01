NAME = libft.a

SRC = *.c

OBJ  = $(SRC:.c=.o) 

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@echo "-----------------------------------"
	@echo "Compiling libft"
	@gcc -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)
	@rm -f ._*

fclean: clean
	@rm -f $(NAME)

re: 
	@make fclean 
	@make all

	