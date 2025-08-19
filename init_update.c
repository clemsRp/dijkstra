
#include "dijkstra.h"

char    **init_not_visited(char ***nodes, int nb_nodes)
{
    int         i;
    int         index;
    char    **res;

    res = malloc(sizeof(char *) * (nb_nodes + 1));
    i = 0;
    index = 0;
    while (nodes[i])
    {
        if (previous_start(nodes, nodes[i][0], i) == 0 && previous_end(nodes, nodes[i][0], i) == 0)
        {
            res[index] = nodes[i][0];
            index++;
        }
        if (previous_start(nodes, nodes[i][1], i) == 0 && previous_end(nodes, nodes[i][1], i) == 0)
        {
            res[index] = nodes[i][1];
            index++;
        }
        i++;
    }
    res[index] = NULL;
    return (res);
}

t_tab   *init_tab(char ***nodes, char *start, int nb_nodes)
{
    int     i;
    int     index;
    t_tab   *res;
    t_duo   temp;
    t_duo   temp2;

    res = malloc(sizeof(t_tab) * (nb_nodes + 1));
    i = 0;
    index = 0;
    temp.node = NULL;
    temp.value = -1;
    temp2.node = start;
    temp2.value = 0;
    while (nodes[i])
    {
        if (previous_start(nodes, nodes[i][0], i) == 0 && previous_end(nodes, nodes[i][0], i) == 0)
        {
            if (ft_strcmp(nodes[i][0], start) == 0)
            {
                res[index].node = start;
                res[index].elem = temp2;
            }
            else
            {
                res[index].node = nodes[i][0];
                res[index].elem = temp;
            }
            index++;
        }
        if (previous_start(nodes, nodes[i][1], i) == 0 && previous_end(nodes, nodes[i][1], i) == 0)
        {
            if (ft_strcmp(nodes[i][1], start) == 0)
            {
                res[index].node = start;
                res[index].elem = temp2;
            }
            else
            {
                res[index].node = nodes[i][1];
                res[index].elem = temp;
            }
            index++;
        }
        i++;
    }
    res[index].node = NULL;
    return (res);
}

void    update_column(t_dict *graph, t_tab *tab, char *start, char *end, int total)
{
    int     tab_v;
    int     list_v;
    int     i;

    tab_v = get_value_in_tab(tab, end);
    list_v = get_value_in_list(get_list(graph, start), end);
    if (tab_v == -1 || tab_v > list_v + total)
    {
        i = 0;
        while (tab[i].node)
        {
            if (ft_strcmp(tab[i].node, end) == 0)
            {
                tab[i].elem.node = start;
                tab[i].elem.value = list_v + total;
            }
            i++;
        }
    }
}

void    update_tab(t_dict *graph, t_tab *tab, char **not_visited, char *start, int total)
{
    int         i;
    t_duo   *list;

    i = 0;
    list = get_list(graph, start);
    while (list[i].node)
    {
        if (in(not_visited, list[i].node) == 1)
            update_column(graph, tab, start, list[i].node, total);
        i++;
    }
}

t_tab   get_minimum(t_tab *tab, char **not_visited)
{
    int         i;
    t_duo   elem;
    t_tab   min;

    i = 0;
    elem.value = -1;
    min.elem = elem;
    while (tab[i].node)
    {
        if (in(not_visited, tab[i].node) == 1 && tab[i].elem.value != -1 && (tab[i].elem.value < min.elem.value || min.elem.value == -1))
        {
            min.elem.value = tab[i].elem.value;
            min.elem.node = tab[i].elem.node;
            min.node = tab[i].node;
        }
        i++;
    }
    return (min);
}