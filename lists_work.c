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

t_asm *new_asm() //init of new list in t_asm
{
    t_asm *new;

    new = (t_asm *)malloc(sizeof(t_asm));
    new->file_name = ft_strnew(0);
    new->name = ft_strnew(0);
    new->comm = ft_strnew(0);
    new->lable = ft_strnew(0);
    new->command = ft_strnew(0);
    new->l_flag[0] = 0;
    new->l_flag[1] = 0;
    new->l_flag[2] = 0;
    new->what_args[0] = 0;
    new->what_args[1] = 0;
    new->what_args[2] = 0;
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

void    check_label_syntax(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (!ft_strchr(LABEL_CHARS, line[i]))
            ft_exit(7);
        i++;
    }
}

void    check_if_label_ok(char *line, int len)
{
    char *t;
    line = line + len + 1;

    if ((t = ft_strchr(line, ':')))
    {
        t--;
        if (*t != '%')
            ft_exit(7);
    }
}

void    get_lable(char *line, t_asm *start)
{
    int len;
    char dupline[1000];

    len = 0;
    if (start->lable[0] == '\0')
    {
        ft_strcpy(dupline, line);
        if (ft_strchr(dupline, LABEL_CHAR) != NULL)
        {
            while (dupline[len] != LABEL_CHAR && dupline[len] != '\0')
                len++;
        }
        check_if_label_ok(line, len);
        if ((dupline[len] == '\0' || dupline[len - 1] == DIRECT_CHAR) && start->only_lable != 1)//check if lable is in line
            start->lable[0] = '\0';
        else if (start->only_lable != 1)
        {
            dupline[len] = '\0';
            ft_strcpy(start->lable, dupline);
            check_label_syntax(start->lable);
            line = line + len + 1;
        }
    }
}

char *get_command(char *line, t_op *g_tab, t_asm *start) {
    int i;
    int j;
    //int flag;
    char *command;
    char *t;

    i = 15;
    //flag = 0;
    while (i >= 0) //dont work when 2 or more commands in line
    {
        if ((t = ft_strstr(line, g_tab[i].command)) != 0)
        {
            j = 0;
            while (g_tab[i].command[j])
                j++;
            t = t + j;
            if (*t == ' ' || *t == '\t' || *t == DIRECT_CHAR)
            {
                command = ft_strnew(6);
                ft_strcpy(command, g_tab[i].command);
                start->command_num = i;
                start->opcode = g_tab[i].opcode;
                return (command);
            }
        }
        i--;
    }
    if (start->lable && !ft_strchr(line, DIRECT_CHAR) && !ft_strchr(line, SEPARATOR_CHAR))
    {
        start->only_lable = 1;
        return (NULL);
    }
    ft_exit(5);
    return(NULL);
}

char *good_strtrim(char *str)
{
    unsigned int i;
    size_t j;
    size_t len;
    char *res;

    i = 0;
    len = ft_strlen(str) - 1;
    j = len;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while ((str[j] == ' ' || str[j] == '\t'))
        j--;
    len = j - i;
    res = ft_strnew(len);
    res = ft_strsub(str, i, len + 1);
    return(res);
}

char *clean_arg(char *line)
{
    size_t i;
    size_t len;
    char *res;

    len = ft_strlen(line);
    i = len;
    while (line[i] != '\t' && line[i] != ' ')
        i--;
    i++;
    res = ft_strnew(len - i);
    res = ft_strsub(line, i, len - i);
    return(res);
}

int     is_num(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) != 1)
            return(0);
        i++;
    }
    return(1);
}

void    get_args(char *line, t_asm *start, t_op *g_tab)
{

    size_t i;
    size_t j;
    size_t k;
  
    char dupline[100];
    char *args;

    i = 0;
    j = 0;
    k = 0;
    ft_strcpy(dupline, line);
    while (dupline[i] != DIRECT_CHAR && dupline[i] != ' ' && dupline[i] != '\t' && dupline[i] != '\0')
        i++;
    if (dupline[i] == '\0' && start->lable == NULL)
        ft_exit(2);
    k = i;
    start->opcode = g_tab[start->command_num].opcode;
    if (start->command_num != -1 && g_tab[start->command_num].args_am == 1)
    {
        start->amount_of_args++;
        while (dupline[i] != COMMENT_CHAR && dupline[i] != '\0')
        {
            i++;
            j++;
        }
        start->args[0] = ft_strnew(j);
        start->args[0] = ft_strsub(dupline, (unsigned int)k + 1, j);
        start->args[0] = good_strtrim(start->args[0]);
        if (start->args[0][0] == DIRECT_CHAR)
        {
            start->what_args[0] = T_DIR;
            if (start->args[0][1] == LABEL_CHAR)

            {
                start->args[0] = start->args[0] + 2;
                start->l_flag[0] = 1;
            }
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
        start->args = ft_strsplit(args, SEPARATOR_CHAR);
        i = 0;
        while (start->args[i] != NULL)
        {
            start->args[i] = good_strtrim(start->args[i]);
            if (ft_strchr(start->args[i], ' ') || ft_strchr(start->args[i], '\t'))
                start->args[i] = clean_arg(start->args[i]);
            start->amount_of_args++;
            if (start->args[i][0] == DIRECT_CHAR)
            {
                start->what_args[i] = T_DIR;
                if (start->args[i][1] == LABEL_CHAR)
                {
                    start->args[i] = start->args[i] + 2;
                    start->l_flag[i] = 1;
                }
            }
            else if (start->args[i][0] == 'r')
                start->what_args[i] = T_REG;
            else if (is_num(start->args[i]) == 1)
                start->what_args[i] = T_IND;
            else
                ft_exit(2);
            i++;
        }
    }
    if (start->command && !start->args[0])
        ft_exit(2);
}

int is_label(char *line) //check if lable is in line
{
    int i;

    i = 0;

    while (line[i] && line[i] != LABEL_CHAR)
        i++;
    if (line[i - 1] == DIRECT_CHAR || line[i] == '\0')
        return(0);
    return(1);
}

void    get_shit(t_asm *start, char *line)
{
    t_op *g_tab;
    if (start->only_lable == 1 && is_label(line) == 1) //if list with only lable
    {
        start = start->next;
        start->next = new_asm();
    }
    line = good_strtrim(line);
    g_tab = init_tab();
    get_lable(line, start);
    start->command = get_command(line, g_tab, start);
    start->args = (char **)malloc(sizeof(char *) * 3);
    get_args(line, start, g_tab);
}