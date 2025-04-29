#include "ft_stock_str.h"

void ft_putstr(char *str);
void ft_putnbr(int n);

void ft_show_tab(struct s_stock_str *par)
{
    int i;

    i = 0;
    while (par[i].str != 0)
    {
        ft_putstr(par[i].str);
        ft_putstr("\n");
        ft_putnbr(par[i].size);
        ft_putstr("\n");
        ft_putstr(par[i].copy);
        ft_putstr("\n");
        i++;
    }
}