
#ifndef DIJKSTRA_H
# define DIJKSTRA_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_duo
{
    char    *node;
    int     value;
}   t_duo;

typedef struct s_tab
{
    char    *node;
    t_duo   elem;
}   t_tab;

typedef struct s_dict
{
    char    *node;
    t_duo   *list;
}   t_dict;

void    print_tab(t_tab *tab);
void    ft_putnbr(int nbr);
void    print_not_visited(char **not_visited);
void    print_distance(t_tab *tab, char *end);
void    swap(char **not_visited, char *node);
void    update_tab(t_dict *graph, t_tab *tab, char **not_visited, char *start, int total);

char    *parser(char *filename);
char    *get_node_in_tab(t_tab *tab, char *node);
char    **ft_split(char *str, char *charset);
char    ***create_list_nodes(char **lines, int nb_words);
char    **init_not_visited(char ***nodes, int nb_nodes);

int     nb_words(char *str, char *charset);
int     print_solution(t_tab *tab, char *start, char *end);
int     ft_strcmp(char *s1, char *s2);
int     ft_atoi(char *str);
int     ft_strlen(char *str);
int     previous_start(char ***nodes, char *node, int k);
int     previous_end(char ***nodes, char *node, int k);
int     nb_nodes(char ***nodes);
int     nb_neighbors(char ***nodes, char *node);
int     is_valid_graph(char ***nodes, char *start, char *end);
int     get_value_in_list(t_duo *list, char *node);
int     get_value_in_tab(t_tab *tab, char *node);
int     in(char **not_visited, char *node);

t_duo   *get_list(t_dict *graph, char *node);

t_dict  *create_graph(char ***nodes);

t_tab   *init_tab(char ***nodes, char *start, int nb_nodes);
t_tab   *solve_graph(t_dict *graph, char ***nodes, char *start);
t_tab   get_minimum(t_tab *tab, char **not_visited);

#endif