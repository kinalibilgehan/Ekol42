/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkinali <bkinali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:45:21 by bkinali           #+#    #+#             */
/*   Updated: 2025/04/28 10:23:05 by bkinali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*numbers;
	int	size;
	int	i;
	
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max -min;
	numbers = (int*)malloc(size * sizeof(int));
	if (numbers == NULL){
		return (-1);
	}
    *range=numbers;
	i = 0;
	while (min + i < max)
	{
		numbers[i] = min + i;
		i++;
	} 
	return (size);
}