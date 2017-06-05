//
// Created by Oleksiy Kres on 6/2/17.
//
#include "op.h"

int	size[] = {4, 4, 0, 0, 0, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};
int codage_octal[] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};

/*int 			if_lable(int *ar)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (ar[i] > 0)
			return (1);
		i++;
	}
	return (0);
}

int 			get_index(int *ar)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		if (ar[i] == 1)
			j = i;
		i++;
	}
	return (j);
}
*/


void	write_codage_octal(t_asm *begin, int fd)
{
	int i;
	char op_b;

	i = 0;
	op_b = 0;
	while (i < begin->amount_of_args)
	{
		if (begin->what_args[i] == T_REG)
			op_b = (op_b << 2) + REG_CODE;
		else if (begin->what_args[i] == T_DIR)
			op_b = (op_b << 2) + DIR_CODE;
		else if (begin->what_args[i] != 0)
			op_b = (op_b << 2) + IND_CODE;
		i++;
	}
	op_b = (op_b <= 0x3 ? op_b << 2 : op_b);
	op_b = (op_b <= 0xF ? op_b << 2 : op_b);
	op_b <<= 2;
	write(fd, &op_b, 1);

}


int 	write_ind(int fd, char *arg, t_t type )
{
	int tmp;

	while (*arg < 48 || *arg > 57)
		arg++;
	if (type == IND)
	{
		tmp = ft_atoi(arg);
		tmp = do_big_endian(tmp, 2);
		write (fd, &tmp, 2);
		return (2);
	}
	else
		tmp = ft_atoi(arg);
	write(fd, &tmp, 1);
	return (1);
}

int 			find_lable(t_asm *begin, char *lable, int val_cur)
{
	t_asm	*node;
	int		res;

	node = begin;
	res = 0;
	while (node)
	{
		if (node->lable && ft_strcmp(node->lable, lable) == 0)
		{
			if (node->program_s >= val_cur)
				return (node->program_s - val_cur);
			else
				return (MAX_SHORT_INT + 1 - (val_cur - node->program_s));
		}
		node = node->next;
	}
	/*if (node && (node->l_flag[0] == 1 || node->l_flag[1] == 1 ||
		node->l_flag[2] == 1))
		res += find_lable(begin, begin->args[get_index(begin->l_flag)]); // проблема с записью лейбы, Антон фикс
	*/
	 return (res);
}

int 	write_dir(int fd, int val_cur, t_asm *head, int index, t_asm *begin)
{
	int tmp;

	if (begin->l_flag[index] == 0)
	{
		while ((*begin->args[index] < 48 || *begin->args[index] > 57) && *begin->args[index] != 45)
			begin->args[index]++;
		tmp = ft_atoi(begin->args[index]);
	}
	else
		tmp = find_lable(head, begin->args[index], val_cur);
	tmp = do_big_endian(tmp, head->cur_size);
	write(fd, &tmp, head->cur_size);
	return (head->cur_size);
}

void	write_op_code(t_asm *head, t_asm *begin, int op_c, int fd)
{
	int i;
	static int val_cur;
	int val_tmp;

	val_tmp = 1;
	i = 0;
	head->cur_size = size[op_c - 1];
	head->cur_codage_octal = codage_octal[op_c - 1];
	write(fd, &op_c, 1);
	if (head->cur_codage_octal && ++val_tmp)
		write_codage_octal(begin, fd);
	while (i < begin->amount_of_args)
	{
		if (begin->what_args[i] == T_REG)
			val_tmp += write_ind(fd, begin->args[i], REG);
		else if (begin->what_args[i] == T_DIR)
			val_tmp += write_dir(fd, val_cur, head, i, begin);
		else if (begin->what_args[i] != 0)
			val_tmp += write_ind(fd, begin->args[i], IND);
		i++;
	}
	val_cur += val_tmp;
}
