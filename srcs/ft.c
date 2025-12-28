
#include "dijkstra.h"

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

int     ft_atoi(char *str)
{
    int     res;
    int     i;

    res = 0;
    i = 0;
    while (str[i])
    {
        res = 10 * res + str[i] - '0';
        i++;
    }
    return (res);
}

void    ft_putnbr(int nbr)
{
    char    c;

    if (nbr > 9)
        ft_putnbr(nbr / 10);
    c = nbr % 10 + '0';
    write(1, &c, 1);
}