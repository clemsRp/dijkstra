
#include "dijkstra.h"

void    algo(char *filename, char *start, char *end)
{
    char    *res;
    char    **lines;
    char    ***nodes;
    t_dict  *graph;
    t_tab   *tab;

    res = parser(filename);
    if (res == NULL)
    {
        write(1, "Erreur de lecture du fichier.\n", 30);
        return ;
    }
    lines = ft_split(res, "\n");
    nodes = create_list_nodes(lines, nb_words(res, "\n"));
    if (is_valid_graph(nodes, start, end) == 0)
    {
        write(1, "Graphe invalide.\n", 17);
        return ;
    }
    graph = create_graph(nodes);
    tab = solve_graph(graph, nodes, start);
    print_solution(tab, start, end);
    print_distance(tab, end);
}

int     main(int argc, char *argv[])
{
    int     i;

    if ((argc - 1) % 3 != 0)
    {
        write(1, "Nombre de parametres invalide.\n", 31);
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        if (ft_strcmp(argv[i + 1], argv[i + 2]) == 0)
        {
            write(1, argv[i + 1], ft_strlen(argv[i + 1]));
            write(1, "; pour une distance totale de 0.\n", 33);
        }
        else
            algo(argv[i], argv[i + 1], argv[i + 2]);
        i += 3;
    }
    return (0);
}