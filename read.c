//
// Created by Anton Repnovskyi on 5/22/17.
//
#include "op.h"

void    ft_exit(int flag)
{
    if (flag == 0)
        ft_putendl("Wrond input");
    exit(0);
}
int     if_comment(char *line)
{
    int i;

    i = 0;
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
        ft_exit(0);
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
            ft_exit(0);
        t++;
    }
    return(name);
}


int main(int ac, char **av)
{
    int fd;
    char *line;
    char *name;
    char *comm;

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        while ((get_next_line(fd, &line)) > 0)
        {
            while (if_comment(line) == 1)
            {
                free(line);
                get_next_line(fd, &line);
            }
            if (ft_strstr(line, ".name"))
                name = get_name_or_comm(line);
            else if (ft_strstr(line, ".comment"))
                comm = get_name_or_comm(line);
            free(line);
        }
        printf("name = %s\ncomment = %s\n", name, comm);
    }
    else
        write(1, "laja\n", 5);
    return (0);
}