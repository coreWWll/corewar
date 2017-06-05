//
// Created by Anton Repnovskyi on 5/31/17.
//

#include "op.h"

void find_label_or_die(t_asm *start, char *label)
{
    t_asm *p;
    t_asm *t;
    int i;

    i = 0;
    p = start;
    while (p)
    {
        if (p->lable)
        {
            if (ft_strcmp(p->lable, label) == 0)
            {
                i = 1;
                break;
            }
        }
        p = p->next;
    }
    if (i != 1)
        ft_exit(6);
}

void check_if_labels(t_asm *start)
{
    t_asm *p;

    p = start;
    while (p)
    {
        if (p->l_flag[0] == 1)
            find_label_or_die(start, p->args[0]);
        if (p->l_flag[1] == 1)
            find_label_or_die(start, p->args[1]);
        if (p->l_flag[2] == 1)
            find_label_or_die(start, p->args[2]);
        p = p->next;
    }
}

void check_args_type(t_asm *p, t_op *tab)
{
    int i;

    i = 0;
    while (i < tab[p->command_num].args_am || (p->command_num == 0 && i == 0))
    {
        if (tab[p->command_num].args[i] != 7)
        {
            if (p->what_args[i] == 1)
            {
                if (tab[p->command_num].args[i] != 1 && tab[p->command_num].args[i] != 3 &&
                    tab[p->command_num].args[i] != 5)
                    ft_exit(2);
            }
            else if (p->what_args[i] == 2)
            {
                if (tab[p->command_num].args[i] != 2 && tab[p->command_num].args[i] != 3 &&
                    tab[p->command_num].args[i] != 6)
                    ft_exit(2);
            }
            else if (p->what_args[i] == 4)
            {
                if (tab[p->command_num].args[i] != 4 && tab[p->command_num].args[i] != 5 &&
                    tab[p->command_num].args[i] != 6)
                    ft_exit(2);
            }
        }
        i++;
    }
}

void check_args_now(t_asm *start, t_op *tab)
{
    t_asm *p;

    p = start;
    while (p)
    {
        if (p->command && p->command[0] != '\0')
        {
            if (p->amount_of_args != tab[p->command_num].args_am)
                ft_exit(2);
            check_args_type(p, tab);
        }
        p = p->next;
    }
}

void    validate_it(t_asm *start, t_op *tab)
{
    check_if_labels(start);
    check_args_now(start, tab);

}