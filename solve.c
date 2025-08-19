
#include "dijkstra.h"

t_tab   *solve_graph(t_dict *graph, char ***nodes, char *start)
{
    int         nb_n;
    int         total;
    char        **not_visited;
    t_tab   *tab;
    t_tab   min;

    total = 0;
    nb_n = nb_nodes(nodes);
    tab = init_tab(nodes, start, nb_n);
    not_visited = init_not_visited(nodes, nb_n);
    swap(not_visited, start);
    while (not_visited[0] && nb_neighbors(nodes, start) > 0)
    {
        update_tab(graph, tab, not_visited, start, total);
        min = get_minimum(tab, not_visited);
        total = min.elem.value;
        start = min.node;
        swap(not_visited, min.node);
    }
    return (tab);
}