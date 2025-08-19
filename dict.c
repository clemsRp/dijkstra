
#include "dijkstra.h"

int     previous_start(char ***nodes, char *node, int k)
{
    int     i;

    i = 0;
    while (nodes[i] && i < k)
    {
        if (ft_strcmp(nodes[i][0], node) == 0)
            return (1);
        i++;
    }
    return (0);
}

int     previous_end(char ***nodes, char *node, int k)
{
    int     i;

    i = 0;
    while (nodes[i] && i < k)
    {
        if (ft_strcmp(nodes[i][1], node) == 0)
            return (1);
        i++;
    }
    return (0);
}

int     nb_nodes(char ***nodes)
{
    int     res;
    int     i;

    res = 0;
    i = 0;
    while (nodes[i])
    {
        if (previous_start(nodes, nodes[i][0], i) == 0)
            res++;
        if (previous_start(nodes, nodes[i][1], i) == 0)
            res++;
        i++;
    }
    return (res);
}

int     nb_neighbors(char ***nodes, char *node)
{
    int     res;
    int     i;

    res = 0;
    i = 0;
    while (nodes[i])
    {
        if (ft_strcmp(nodes[i][0], node) == 0)
            res++;
        i++;
    }
    return (res);
}

int     get_value_in_list(t_duo *list, char *node)
{
    int     i;

    i = 0;
    while (list[i].node)
    {
        if (ft_strcmp(list[i].node, node) == 0)
            return (list[i].value);
        i++;
    }
    return (-1);
}

char    *get_node_in_tab(t_tab *tab, char *node)
{
    int     i;

    i = 0;
    while (tab[i].node)
    {
        if (ft_strcmp(tab[i].node, node) == 0)
            return (tab[i].elem.node);
        i++;
    }
    return (NULL);
}

int     get_value_in_tab(t_tab *tab, char *node)
{
    int     i;

    i = 0;
    while (tab[i].node)
    {
        if (ft_strcmp(tab[i].node, node) == 0)
            return (tab[i].elem.value);
        i++;
    }
    return (-1);
}

t_duo   *get_list(t_dict *graph, char *node)
{
    int     i;

    i = 0;
    while (graph[i].node)
    {
        if (ft_strcmp(graph[i].node, node) == 0)
            return (graph[i].list);
        i++;
    }
    return (NULL);
}