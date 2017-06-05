//
// Created by Anton Repnovskyi on 5/22/17.
//
#include "op.h"

void    ft_exit(int flag)
{
    if (flag == 0)
        ft_putendl("Wrong name or comment format");
    if (flag == 1)
        ft_putendl("Size of name or comment is too big");
    if (flag == 2)
        ft_putendl("Wrong argument");
    if (flag == 3)
        ft_putendl("Wrong format of file");
    if (flag == 5)
        ft_putendl("No command or wrong command");
    if (flag == 6)
        ft_putendl("Wrong label");
    if (flag == 7)
        ft_putendl("Wrong label syntax");
    exit(0);
}

int     if_comment(char *line)
{
    int i;

    i = 0;
    if (line[0] == '\0')
        return(1);
    while (line[i] == ' ' || line[i] == '\t' || line[i] == COMMENT_CHAR)
    {
        if (line[i] == COMMENT_CHAR)
            return(1);
        i++;
    }
    return((line[i] == '\0') ? 1: 0);
}

void check_endl_and_len(char *t, char *name, int flag)
{
    t++;
    while (*t != '\0')
    {
        if (*t != ' ' && *t != '\t')
            ft_exit(0);
        t++;
    }
    if ((flag == 1 && ft_strlen(name) > PROG_NAME_LENGTH) //checking of name and comment size
        || (flag == 0 && ft_strlen(name) > COMMENT_LENGTH))
        ft_exit(1);
}

char *get_name_or_comm(char *line, int flag)
{
    char *t;
    char *name;
    size_t len;
    size_t i;

    i = 0;
    len = 0;
    if (!(t = ft_strchr(line, '\"')))
        ft_exit(0);
    t++;
    while (t[len] != '\"' && t[len] != '\0')
        len++;
    if (t[len] != '\"')
        ft_exit(0);
    name = ft_strnew(len);
    while (i < len)
    {
        name[i] = *t;
        t++;
        i++;
    }
    check_endl_and_len(t, name, flag);
    return(name);
}

char    *get_file_name(char *av)
{
    size_t len;
    char *name;

    name = ft_strnew(0);
    len = ft_strlen(av);
    while (len > 0 && av[len - 1] != '/')
        len--;
    while (av[len] != '.')
    {
        name = ft_charjoin(name, av[len]);
        len++;
    }
    return (name);
}

void    make_list(t_asm **start, char *line)
{
    t_asm *p;

    p = *start;
    while (p)
    {
        if (p->only_label == 1) // check if label is empty to add command in it
        {
            get_shit(p, line);
            p->only_label = 0;
            break;
        }
        else if(p->next == NULL)
        {
            if (p->command || p->label)
            {
                p->next = new_asm();
                p = p->next;
            }
            get_shit(p, line);
            if (p->only_label != 1)
                p->next = new_asm();
            break;
        }
        if (p->only_label == 1 && p->next->only_label == 1) //to unmark list with empty label
            p->only_label = 0;
        p = p->next;
    }
}

void check_format(char *file)
{
    size_t len;

    len = ft_strlen(file);

    if (file[len - 1] != 's' && file[len - 2] != '.')//checking file format by last 2 chars
        ft_exit(3);
}

void    do_parsing_work(char *av, t_asm *start)
{
    char *line;
    int fd;

    if ((fd = open(av, O_RDONLY)) != -1)
    {
        while ((get_next_line(fd, &line)) > 0)
        {
            if (ft_strstr(line, NAME_CMD_STRING))
                start->name = get_name_or_comm(line, 1);
            else if (ft_strstr(line, COMMENT_CMD_STRING))
                start->comm = get_name_or_comm(line, 0);
            else if (if_comment(line) != 1)
                make_list(&start, line);
            //ft_strdel(&line);
        }
        printf("name = %s\ncomment = %s\nfilename = %s\n", start->name, start->comm, start->file_name);
    }
    else
        ft_exit(3);
}

int main(int ac, char **av)
{
    t_asm *start;
    t_op *tab;

    if (ac == 2)
    {
        start = new_asm();
        start->file_name = (av[1][0] == '.') ? get_file_name(av[1]) : av[1];
        check_format(av[1]);//checking file format
        do_parsing_work(av[1], start);
        tab = init_tab();
        validate_it(start, tab);
        to_byte_code(start);
    }
    else
        write(1, "Usage: ./asm [path to the champion_file.s]\n", 43);
    //sleep(20);
    return (0);
}