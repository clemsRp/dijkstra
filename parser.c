
#include "dijkstra.h"

int     is_valid_char(char c)
{
    if (c == '\n' || c == '-' || c == '>' || c == ':' || (c >= '0' && c <= '9')
        || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}

char    *parser(char *filename)
{
    int         fd;
    int         i;
    int         size;
    char    c;
    char    *res;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    size = 0;
    while (read(fd, &c, 1))
    {
        if (is_valid_char(c) == 1)
            size++;
    }
    close(fd);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    res = malloc(sizeof(char) * (size + 1));
    i = 0;
    while (read(fd, &c, 1))
    {
        if (is_valid_char(c) == 1)
            res[i++] = c;
    }
    res[i] = '\0';
    close(fd);
    return (res);
}