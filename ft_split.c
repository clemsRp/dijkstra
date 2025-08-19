
#include "dijkstra.h"

int     sep(char c, char *charset)
{
    int     i;

    i = 0;
    while (charset[i])
    {
        if (charset[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int     nb_words(char *str, char *charset)
{
    int     i;
    int     res;

    i = 0;
    res = 0;
    while (str[i + 1])
    {
        if (sep(str[i], charset) == 0 && sep(str[i + 1], charset) == 1)
            res++;
        i++;
    }
    if (sep(str[i], charset) == 0)
        res++;
    return (res);
}

int     ind_start(char *str, char *charset, int index)
{
    int     i;

    i = 0;
    while (sep(str[i], charset) == 1)
        i++;
    while (index > 0)
    {
        while (sep(str[i], charset) == 0)
            i++;
        while (sep(str[i], charset) == 1)
            i++;
        index--;
    }
    return (i);
}

int     ind_end(char *str, char *charset, int index)
{
    int     i;

    i = 0;
    while (index + 1 > 0)
    {
        while (sep(str[i], charset) == 1)
            i++;
        while (sep(str[i], charset) == 0)
            i++;
        index--;
    }
    return (i - 1);
}

char    *add_word(int start, int end, char *str)
{
    char    *res;
    int         i;

    i = start;
    res = malloc(sizeof(char) * (end - start + 2));
    while (i <= end)
    {
        res[i - start] = str[i];
        i++;
    }
    res[i - start] = '\0';
    return (res);
}

char    **ft_split(char *str, char *charset)
{
    int         i;
    char    **res;

    i = 0;
    res = malloc(sizeof(char *) * (nb_words(str, charset) + 1));
    while (i < nb_words(str, charset))
    {
        res[i] = add_word(ind_start(str, charset, i), ind_end(str, charset, i), str);
        i++;
    }
    res[i]= NULL;
    return (res);
}