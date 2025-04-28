/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkinali <bkinali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:52:28 by bkinali           #+#    #+#             */
/*   Updated: 2025/04/27 10:10:29 by bkinali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strcmp(char *a, char *b)
{
	while (*a != '\0' && *b != '\0' && *a == *b)
	{
		a++;
		b++;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc > 0)
	{
		i = 0;
		while (++i < argc - 1)
		{
			j = 0;
			while (++j < argc - i)
				if (ft_strcmp(argv[j], argv[j + 1]) > 0)
					ft_swap(&argv[j], &argv[j + 1]);
		}
		i = 0;
		while (++i < argc)
		{
			j = -1;
			while (++j < ft_strlen(argv[i]))
				ft_putchar(argv[i][j]);
			ft_putchar('\n');
		}
	}
	return (0);
}
