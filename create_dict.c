
#include "dijkstra.h"

char    ***create_list_nodes(char **lines, int nb_words)
{
    int         i;
    char    ***nodes;

    nodes = malloc(sizeof(char **) * (nb_words + 1));
    i = 0;
    while (lines[i])
    {
        nodes[i] = ft_split(lines[i], "->:");
        i++;
    }
    nodes[i] = NULL;
    return (nodes);
}

t_duo   create_duo(char **node)
{
    t_duo   res;

    res.node = node[1];
    res.value = ft_atoi(node[2]);
    return (res);
}

t_dict  create_dict(char ***nodes, char *node)
{
    int     i;
    int     index;
    int     nb_n;
    t_dict  res;

    i = 0;
    index = 0;
    nb_n = nb_neighbors(nodes, node);
    res.list = malloc(sizeof(t_duo) * (nb_n + 1));
    while (index < nb_n)
    {
        if (ft_strcmp(nodes[i][0], node) == 0)
        {
            res.list[index] = create_duo(nodes[i]);
            index++;
        }
        i++;
    }
    res.list[index].node = NULL;
    res.node = node;
    return (res);
}

t_dict  *create_graph(char ***nodes)
{
    int     i;
    int     index;
    t_dict  *res;

    i = 0;
    index = 0;
    res = malloc(sizeof(t_dict) * (nb_nodes(nodes) + 1));
    while (nodes[i])
    {
        if (previous_start(nodes, nodes[i][0], i) == 0)
        {
            res[index] = create_dict(nodes, nodes[i][0]);
            index++;
        }
        i++;
    }
    res[index].node = NULL;
    return (res);
}