
#include "dijkstra.h"

void    swap(char **not_visited, char *node)
{
    int         i;
    int         j;

    i = 0;
    while (not_visited[i])
    {
        if (ft_strcmp(not_visited[i], node) == 0)
            j = i;
        i++;
    }
    if (j != i - 1)
        not_visited[j] = not_visited[i - 1];
    not_visited[i - 1] = NULL;
}

int     in(char **not_visited, char *node)
{
    int     i;

    i = 0;
    while (not_visited[i])
    {
        if (ft_strcmp(not_visited[i], node) == 0)
            return (1);
        i++;
    }
    return (0);
}

void    print_tab(t_tab *tab)
{
    int     i;

    i = 0;
    while (tab[i].node)
    {
        __builtin_printf("{%s: [%s: %d]}\n", tab[i].node, tab[i].elem.node, tab[i].elem.value);
        i++;
    }
}

void    print_not_visited(char **not_visited)
{
    int     i;

    i = 0;
    while (not_visited[i])
    {
        __builtin_printf("%s, ", not_visited[i]);
        i++;
    }
    __builtin_printf("\n\n");
}

int     print_solution(t_tab *tab, char *start, char *end)
{
    if (get_value_in_tab(tab, end) == -1)
    {
        write(1, "Il n'y a aucun chemin possible pour aller de ", 45);
        write(1, start, ft_strlen(start));
        write(1, " a ", 3);
        write(1, end, ft_strlen(end));
        write(1, ".\n", 2);
        return (0);
    }
    if (ft_strcmp(start, end) == 0)
        write(1, start, ft_strlen(start));
    else
    {
        print_solution(tab, start, get_node_in_tab(tab, end));
        write(1, " -> ", 4);
        write(1, end, ft_strlen(end));
    }
    return (1);
}

void    print_distance(t_tab *tab, char *end)
{
    int     distance;

    write(1, "; pour une distance totale de ", 30);
    distance = get_value_in_tab(tab, end);
    ft_putnbr(distance);
    write(1, ".\n", 2);
}