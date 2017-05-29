//
// Created by Anton Repnovskyi on 5/24/17.
//

#include "op.h"

t_op 		*init_tab(void) {
    static t_op g_op_tab[17] = {
            {"live",  1, {T_DIR},                                               1,  10,   0},
            {"ld",    2, {T_DIR | T_IND,         T_REG},                        2,  5,    1},
            {"st",    2, {T_REG, T_IND | T_REG},                                3,  5,    1},
            {"add",   3, {T_REG, T_REG, T_REG},                                 4,  10,   1},
            {"sub",   3, {T_REG, T_REG, T_REG},                                 5,  10,   1},
            {"and",   3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6,  6,    1},
            {"or",    3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7,  6,    1},
            {"xor",   3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8,  6,    1},
            {"zjmp",  1, {T_DIR},                                               9,  20,   0},
            {"ldi",   3, {T_REG | T_DIR | T_IND, T_DIR | T_REG,         T_REG}, 10, 25,   1},
            {"sti",   3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},         11, 25,   1},
            {"fork",  1, {T_DIR},                                               12, 800,  0},
            {"lld",   2, {T_DIR | T_IND,         T_REG},                        13, 10,   1},
            {"lldi",  3, {T_REG | T_DIR | T_IND, T_DIR | T_REG,         T_REG}, 14, 50,   1},
            {"lfork", 1, {T_DIR},                                               15, 1000, 0},
            {"aff",   1, {T_REG},                                               16, 2,    1},
            {0,       0, 0,                                                     0,  0,    0}
    };
    return(g_op_tab);
}

t_asm *new_asm()
{
    t_asm *new;

    new = (t_asm *)malloc(sizeof(t_asm));
    new->file_name = ft_strnew(0);
    new->name = ft_strnew(0);
    new->comm = ft_strnew(0);
    new->lable = ft_strnew(0);
    new->l_flag[0] = 0;
    new->l_flag[1] = 0;
    new->l_flag[2] = 0;
    new->amount_of_args = 0;
    new->command_num = -1;
    new->only_lable = 0;
    new->opcode = 0;
    new->carry = 98;
    new->c_oct = 0;
    new->label_size = 0;
    new->next = NULL;
    return (new);
}

void    get_lable(char *line, t_asm *start)
{
    int i;
    int len;
    char dupline[1000];
    //char *label;

    i = 0;
    len = 0;
    if (start->lable[0] == '\0')
    {
        ft_strcpy(dupline, line);
        if (ft_strchr(dupline, ':') != NULL)
        {
            while (dupline[len] != ':' && dupline[len] != '\0')
                len++;
        }
        if ((dupline[len] == '\0' || dupline[len - 1] == '%') && start->only_lable != 1)
            start->lable = NULL;
        else if (start->only_lable != 1)
        {
            dupline[len] = '\0';
            ft_strcpy(start->lable, dupline);
        }
       // else if (start->only_lable != 1)

    }
   /* len = ft_strlen(line);
    while (line[len] == ' ' || line[len] == '\t')
        len--;*/
}

char *get_command(char *line, t_op *g_tab, t_asm *start) {
    int i;
    int len;
    char *command;

    i = 15;
    len = 0;
    while (i >= 0)
    {
        if (ft_strstr(line, g_tab[i].command) != 0)
        {
            command = (char *)malloc(sizeof(char) * 6);
            ft_strcpy(command, g_tab[i].command);
            start->command_num = i;
            return(command);
        }
        i--;
    }
    if (start->lable)
    {
        start->only_lable = 1;
        return (NULL);
    }
    ft_exit(3);
    return(NULL);
}

char *good_strtrim(char *str)
{
    int i;
    int j;
    size_t len;
    char *res;

    i = 0;
    j = 0;
    len = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t')
            len++;
        i++;
    }
    res = ft_strnew(len);
    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (j < len)
    {
        res[j] = str[i];
        i++;
        j++;
    }
    return(res);
}

void    get_args(char *line, t_asm *start, t_op *g_tab)
{
    int i;
    int j;
    int k;
    char dupline[100];
    char *args;

    i = 0;
    j = 0;
    k = 0;
    ft_strcpy(dupline, line);
    while (dupline[i] == ' '|| dupline[i] == '\t')
        i++;
    while (dupline[i] != '%' && dupline[i] != ' ' && dupline[i] != '\t' && dupline[i] != '\0')
        i++;
    if (dupline[i] == '\0' && start->lable == NULL)
        ft_exit(3);
    k = i;
    start->opcode = g_tab[start->command_num].opcode;
    if (start->command_num != -1 && g_tab[start->command_num].args_am == 1)
    {
        while (dupline[i] != '#' && dupline[i] != '\0')
        {
            i++;
            j++;
        }
        start->args[0] = ft_strnew(j);
        start->args[0] = ft_strsub(dupline, k + 1, j);
        start->args[0] = good_strtrim(start->args[0]);
        if (start->args[0][0] == '%')
        {
            start->what_args[0] = T_DIR;
            if (start->args[0][1] == ':')
                start->l_flag[0] = 1;
        }
        else if (dupline[k] == 'r')
            start->what_args[0] = T_REG;
    }
    else
    {
        j = ft_strlen(line);
        while (dupline[k] == ' ' || dupline[k] == '\t')
            k++;
        args = ft_strsub(line, k, j);
        start->args = ft_strsplit(args, ',');
        i = 0;
        while (start->args[i] != NULL)
        {
            start->args[i] = good_strtrim(start->args[i]);
            start->amount_of_args++;
            if (start->args[i][0] == '%')
            {
                start->what_args[i] = T_DIR;
                if (start->args[i][1] == ':')
                    start->l_flag[i] = 1;
            }
            else if (start->args[i][0] == 'r')
                start->what_args[i] = T_REG;
            else
                start->what_args[i] = T_IND;
            i++;
        }
    }
}

int is_label(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] != ':')
        i++;
    if (line[i - 1] == '%' || line[i] == '\0')
        return(0);
    return(1);
}

void    get_shit(t_asm *start, char *line)
{
    t_op *g_tab;

    if (start->only_lable == 1 && is_label(line) == 1)
    {
        start = start->next;
        start->next = new_asm();
    }
    g_tab = init_tab();
    get_lable(line, start);
    start->command = get_command(line, g_tab, start);
    start->args = (char **)malloc(sizeof(char *) * 3);
    get_args(line, start, g_tab);

}