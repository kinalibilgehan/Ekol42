/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkinali <bkinali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:54:12 by bkinali           #+#    #+#             */
/*   Updated: 2025/04/19 11:43:29 by bkinali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkinali <bkinali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:54:12 by bkinali           #+#    #+#             */
/*   Updated: 2025/04/17 12:58:03 by bkinali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char			*hex_chars;
	unsigned char	c;

	hex_chars = "0123456789abcdef";
	while (*str)
	{
		c = (unsigned char)*str;
		if (c <= 31 || c == 127)
		{
			ft_putchar('\\');
			ft_putchar(hex_chars[c / 16]);
			ft_putchar(hex_chars[c % 16]);
		}
		else
		{
			ft_putchar(c);
		}
		str++;
	}
}
