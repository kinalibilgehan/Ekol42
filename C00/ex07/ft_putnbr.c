/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkinali <bkinali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:16:51 by bkinali           #+#    #+#             */
/*   Updated: 2025/04/12 22:58:16 by bkinali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	z;
	int		bolen;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	bolen = 1;
	while (nb / bolen >= 10)
	{
		bolen *= 10;
	}
	while (bolen > 0)
	{
		z = nb / bolen + '0';
		write(1, &z, 1);
		nb %= bolen;
		bolen /= 10;
	}
}
