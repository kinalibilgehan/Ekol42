#include <stdlib.h>

typedef struct s_stock_str
{
    int             size;
    char            *str;
    char            *copy;
}               t_stock_str;

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

t_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *tab;
    int i;

    tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
    if (!tab)
        return (NULL);
    i = 0;
    while (i < ac)
    {
        tab[i].size = ft_strlen(av[i]);
        tab[i].str = av[i];
        tab[i].copy = (char *)malloc(sizeof(char) * (tab[i].size + 1));
        if (!tab[i].copy)
        {
            while (i >= 0)
            {
                free(tab[i].copy);
                i--;
            }
            free(tab);
            return (NULL);
        }
        ft_strcpy(tab[i].copy, av[i]);
        i++;
    }
    tab[i].str = 0;
    return (tab);
}