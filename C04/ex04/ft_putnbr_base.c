/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkinali <bkinali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:24:42 by bkinali           #+#    #+#             */
/*   Updated: 2025/04/24 09:59:49 by bkinali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	base_check(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (0);
	i = 0;
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(long nbr, char *base, int base_len)
{
	long	divisor;
	char	digit_char;

	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	divisor = 1;
	while (nbr / divisor >= base_len)
	{
		divisor *= base_len;
	}
	while (divisor > 0)
	{
		digit_char = base[nbr / divisor];
		ft_putchar(digit_char);
		nbr %= divisor;
		divisor /= base_len;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	temp_nbr;

	base_len = ft_strlen(base);
	if (!base_check(base))
		return ;
	temp_nbr = nbr;
	if (temp_nbr < 0)
	{
		ft_putchar('-');
		temp_nbr = -temp_nbr;
	}
	print_number(temp_nbr, base, base_len);
}
