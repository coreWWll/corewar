NAME = asm

FLAGS =	-Wall -Wextra -Werror 

SRC =	main.c\
		first_check.c\
		first_parse.c\
		get_name_and_comment.c\
		more_checks.c\
		parse_args.c\
		parse_in_list.c\
		support.c\
		validation.c\
		convert.c\
		work_with_header.c\
		work_with_commands.c\

LIBFT = libft/libft.a

SRO  =  $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		@$(MAKE) -C libft
		@echo "-----------------------------------"
		@echo "Compiling asm"
		@gcc $(FLAGS) -c $(SRC) ../op.c
		@gcc $(FLAGS) -o $(NAME) op.o $(SRO) $(LIBFT)
		@echo "-----------------------------------"
		@echo "asm is ready"
clean:
	@rm -f $(SRO) op.o
	@$(MAKE) clean -C libft
	@echo "-----------------------------------"
	@echo "Objects successfully removed"
fclean:	
	@make clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft
	@echo "-----------------------------------"
	@echo "asm successfully removed"

re: 
	@make fclean
	@make all