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
    new->file_name = NULL;
    new->name = NULL;
    new->comm = NULL;
    new->label = NULL;
    new->command = NULL;
    new->l_flag[0] = 0;
    new->l_flag[1] = 0;
    new->l_flag[2] = 0;
    new->what_args[0] = 0;
    new->what_args[1] = 0;
    new->what_args[2] = 0;
    new->amount_of_args = 0;
    new->command_num = -1;
    new->only_label = 0;
    new->opcode = 0;
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
    char *p;

    p = line + len + 1;
    if ((t = ft_strchr(p, LABEL_CHAR)))
    {
        t--;
        if (*t != DIRECT_CHAR)
            ft_exit(7);
    }
    //free(p);
}

void    get_label(char *line, t_asm *start)
{
    int len;
    char dupline[1000];

    len = 0;
    if (start->label == NULL)
    {
        ft_strcpy(dupline, line);
        if (ft_strchr(dupline, LABEL_CHAR) != NULL)
        {
            while (dupline[len] != LABEL_CHAR && dupline[len] != '\0')
                len++;
        }
        check_if_label_ok(line, len);
        if ((dupline[len] == '\0' || dupline[len - 1] == DIRECT_CHAR) && start->only_label != 1)//check if label is in line
            start->label = start->label;
        else if (start->only_label != 1 && len != 0)
        {
            dupline[len] = '\0';
            start->label = ft_strnew(0);
            ft_strcpy(start->label, dupline);
            check_label_syntax(start->label);
        }
    }
}

void get_command(char *line, t_op *g_tab, t_asm *start) {
    int i;
    int j;
    char *t;

    i = 15;
    while (i >= 0) //sometimes works when 2 or more commands in line
    {
        if ((t = ft_strstr(line, g_tab[i].command)) != 0)
        {
            j = 0;
            while (g_tab[i].command[j])
                j++;
            t = t + j;
            if (*t == ' ' || *t == '\t' || *t == DIRECT_CHAR)
            {
                start->command = ft_strnew(6);
                ft_strcpy(start->command, g_tab[i].command);
                start->command_num = i;
                start->opcode = g_tab[i].opcode;
                break ;
            }
        }
        i--;
    }
    if (start->label && !ft_strchr(line, DIRECT_CHAR) && !ft_strchr(line, SEPARATOR_CHAR))
        start->only_label = 1;
    if (!start->label && !start->command)
        ft_exit(5);
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
    res = ft_strsub(line, (unsigned int)i, len - i);
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

void  if_one_arg(t_asm *start, char *dupline, size_t i)
{
    size_t j;
    char *temp;

    j = 0;
    start->amount_of_args++;
    while (dupline[i + j] != COMMENT_CHAR && dupline[i + j] != '\0')
        j++;
    start->args= (char **)malloc(sizeof(char *));
    start->args[0] = ft_strsub(dupline, (unsigned int)i + 1, j);
    temp = start->args[0];
    start->args[0] = good_strtrim(temp);
    free(temp);
    if (start->args[0][0] == DIRECT_CHAR)
    {
        start->what_args[0] = T_DIR;
        if (start->args[0][1] == LABEL_CHAR)
        {
            temp = start->args[0];
            start->args[0] = ft_strsub(temp, 2, ft_strlen(temp) - 2);
            free(temp);
            start->l_flag[0] = 1;
        }
    }
    else if (dupline[i] == 'r')
        start->what_args[0] = T_REG;
}

void    if_more_args(t_asm *start)
{
    int i;
    char *temp;

    i = 0;
    while (start->args[i] != NULL)
    {
        temp = start->args[i];
        start->args[i] = good_strtrim(temp);
        free(temp);
        if (ft_strchr(start->args[i], ' ') || ft_strchr(start->args[i], '\t'))
        {
            temp = start->args[i];
            start->args[i] = clean_arg(temp);
            free(temp);
        }
        start->amount_of_args++;
        if (start->args[i][0] == DIRECT_CHAR)
        {
            start->what_args[i] = T_DIR;
            if (start->args[i][1] == LABEL_CHAR)
            {
                temp = start->args[i];
                start->args[i] = ft_strsub(temp, 2, ft_strlen(temp) - 2);
                free(temp);
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

void    get_args_now(t_asm *start, t_op *tab, char *dupline, size_t i)
{
    size_t j;
    char *args;

    if (start->command_num != -1 && tab[start->command_num].args_am == 1)
        if_one_arg(start, dupline, i);
    else
    {
        j = ft_strlen(dupline);
        while (dupline[i] == ' ' || dupline[i] == '\t')
            i++;
        args = ft_strsub(dupline, (unsigned int)i, j);
        start->args = ft_strsplit(args, SEPARATOR_CHAR);
        ft_strdel(&args);
        if_more_args(start);
    }
}

void    get_args(char *line, t_asm *start, t_op *tab)
{
    size_t i;
    char dupline[100];

    i = 0;
    ft_strcpy(dupline, line);
    while (dupline[i] != DIRECT_CHAR && dupline[i] != ' ' && dupline[i] != '\t' && dupline[i] != '\0')
        i++;
    if (dupline[i] == '\0' && start->label == NULL)
        ft_exit(2);
    start->opcode = tab[start->command_num].opcode;
    get_args_now(start, tab, dupline, i);
    if (start->command && !start->args[0])
        ft_exit(2);
}

int is_label(char *line) //check if label is in line
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
    if (start->only_label == 1 && is_label(line) == 1) //if list with only label
    {
        start->next = new_asm();
        start->only_label = 0;
        start = start->next;
    }
    line = good_strtrim(line);
    g_tab = init_tab();
    get_label(line, start);
    get_command(line, g_tab, start);
    get_args(line, start, g_tab);
    free(line);
}
