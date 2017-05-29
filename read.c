//
// Created by Anton Repnovskyi on 5/22/17.
//
#include "op.h"

void    ft_exit(int flag)
{
    if (flag == 0)
        ft_putendl("Wrond input");
    if (flag == 1)
        ft_putendl("Wrond input 2");
    if (flag == 2)
        ft_putendl("Wrond input 3");
    if (flag == 3)
        ft_putendl("Wrond input 4");
    exit(0);
}

int     if_comment(char *line)
{
    int i;

    i = 0;
    if (line[0] == '\0')
        return(1);
    while (line[i] == ' ' || line[i] == '#')
    {
        if (line[i] == '#')
            return(1);
        i++;
    }
    return(0);
}

char *get_name_or_comm(char *line)
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
        ft_exit(1);
    name = ft_strnew(len);
    while (i < len)
    {
        name[i] = *t;
        t++;
        i++;
    }
    t++;
    while (*t != '\0')
    {
        if (*t != ' ' && *t != '\t')
            ft_exit(2);
        t++;
    }
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
        if(p->next == NULL) //possible segfault!!!!
        {
            p->next = new_asm();
            get_shit(p, line);
            break;
        }
        p = p->next;
    }
}


int main(int ac, char **av)
{
    int fd;
    t_asm *start;
    char *line;

    start = new_asm();
    start->file_name = (av[1][0] == '.') ? get_file_name(av[1]) : av[1];
    if (ac == 2)
    {
        if ((fd = open(av[1], O_RDONLY)) != -1)
        {
            while ((get_next_line(fd, &line)) > 0)
            {
                while (if_comment(line) == 1)
                {
                    free(line);
                    get_next_line(fd, &line);
                }
                if (ft_strstr(line, NAME_CMD_STRING))
                    start->name = get_name_or_comm(line); //should check it len
                else if (ft_strstr(line, COMMENT_CMD_STRING))
                    start->comm = get_name_or_comm(line); //should check it len
                else
                    make_list(&start, line);
                free(line);
            }
            printf("name = %s\ncomment = %s\nfilename = %s\n", start->name, start->comm, start->file_name);
        }
        else
            write(1, "this! is! lajjaaaaa!\n", 21);
    }
    else
        write(1, "laja\n", 5);
    /*t_asm *p;
    p = start;
    while (p)
    {
        printf("lable = %s,  command = %s, args = %s, %s, %s what_args = %d, %d, %d  l_flag = %d,%d,%d\n", p->lable, p->command, p->args[0],p->args[1], p->args[2], p->what_args[0], p->what_args[1],
        p->what_args[2], p->l_flag[0], p->l_flag[1], p->l_flag[2]);
        p = p->next;
    }*/
    return (0);
}