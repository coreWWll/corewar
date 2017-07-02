NAME = virtual_machine

#FLAGS =	-Wall -Wextra -Werror

SRC =	corewar.c\
        create_players.c\
        live_operation.c\
        print_memory.c\
        read_player_file.c\
        run_operation.c\
        start_battle.c\
        move_carr_and_do_operations.c\
        live_operation.c\
        ld_operation.c\
        st_operation.c\
        add_operation.c\
        sub_operation.c\
        ft_memdup.c\
        and_operation.c\
        or_operation.c\
        xor_operation.c\
        error.c\
        get_op_code.c\
        zjmp_operation.c\
        ldi_operation.c\
        sti_operation.c\
        fork_operation.c\
        lld_operation.c\
        lldi_operation.c\
        lfork_operation.c\
        aff_operation.c\
        get_flags.c\
        create_map.c\
        memory_dump.c\
        operations_with_car.c\
        get_args_and_value.c\
        get_args_and_values_part_2.c\
        dump_memory.c\
        put_int_on_map.c\
        bonus/visualisation.c\
        bonus/visualisate.c\
        bonus/w_print_memory.c\
        bonus/w_print_param.c\
        bonus/w_print_usage.c\
        bonus/put_caret_on_map.c\
        bonus/time.c\
       	bonus/check_if_refresh.c\
        bonus/read_commands.c\
        bonus/create_windows.c\

LIBFT = libft/libft.a

SRO  =  $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		@$(MAKE) -C libft
		@echo "-----------------------------------"
		@echo "Compiling virtual_machine"
		@gcc $(FLAGS) -c $(SRC) ../op.c
		@echo "2"
		@gcc $(FLAGS) -o $(NAME) op.o $(SRO) $(LIBFT)
		@echo "-----------------------------------"
		@echo "virtual_machine is ready"
clean:
	@rm -f $(SRO) op.o
	@$(MAKE) clean -C libft
	@echo "-----------------------------------"
	@echo "Objects successfully removed"
fclean:	
	@make clean
	@rm -f $(NAME) bonus
	@$(MAKE) fclean -C libft
	@echo "-----------------------------------"
	@echo "virtual_machine successfully removed"

re: 
	@make fclean
	@make all
