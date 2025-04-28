/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkinali <bkinali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:08:16 by bkinali           #+#    #+#             */
/*   Updated: 2025/04/27 10:05:59 by bkinali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*program_name;
	int		len;

	if (argc > 0)
	{
		program_name = argv[0];
		len = 0;
		while (program_name[len] != '\0')
			len++;
		write(1, program_name, len);
		write(1, "\n", 1);
	}
	return (0);
}
