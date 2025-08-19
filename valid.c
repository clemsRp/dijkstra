
#include "dijkstra.h"

int     is_numeric(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int     is_alpha(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return (0);
        i++;
    }
    return (1);
}

int     is_valid_graph(char ***nodes, char *start, char *end)
{
    int     i;
    int     j;
    int     s1;
    int     s2;

    i = 0;
    s1 = 0;
    s2 = 0;
    while (nodes[i])
    {
        if (ft_strcmp(nodes[i][0], start) == 0 || ft_strcmp(nodes[i][1], start) == 0)
            s1++;
        if (ft_strcmp(nodes[i][0], end) == 0 || ft_strcmp(nodes[i][1], end) == 0)
            s2++;
        j = 0;
        while (nodes[i][j])
        {
            if (j == 2)
            {
                if (is_numeric(nodes[i][j]) == 0)
                    return (0);
            }
            else
            {
                if (is_alpha(nodes[i][j]) == 0)
                    return (0);
            }
            j++;
        }
        if (j != 3)
            return (0);
        i++;
    }
    if (s1 < 1 || s2 < 1)
        return (0);
    return (1);
}