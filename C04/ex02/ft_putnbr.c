/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkinali <bkinali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:18:24 by bkinali           #+#    #+#             */
/*   Updated: 2025/04/23 16:04:22 by bkinali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	temp_nb;
	long	divisor;
	char	digit_char;

	temp_nb = nb;
	divisor = 1;
	if (temp_nb < 0)
	{
		ft_putchar('-');
		temp_nb = -temp_nb;
	}
	if (temp_nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (temp_nb / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		digit_char = (temp_nb / divisor) + '0';
		ft_putchar(digit_char);
		temp_nb %= divisor;
		divisor /= 10;
	}
}
