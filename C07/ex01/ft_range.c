/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkinali <bkinali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:28:08 by bkinali           #+#    #+#             */
/*   Updated: 2025/04/27 00:44:41 by bkinali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*numbers;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	numbers = (int *)malloc(size * sizeof(int));
	if (numbers == NULL)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		numbers[i] = min + i;
		i++;
	}
	return (numbers);
}
