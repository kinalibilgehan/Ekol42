/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkinali <bkinali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:42:54 by bkinali           #+#    #+#             */
/*   Updated: 2025/04/21 07:43:42 by bkinali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*p;
	char	*haystack;
	char	*needle;

	if (*to_find == '\0')
		return (str);
	p = str;
	while (*p != '\0')
	{
		haystack = p;
		needle = to_find;
		while (*haystack != '\0' && *needle != '\0' && *haystack == *needle)
		{
			haystack++;
			needle++;
		}
		if (*needle == '\0')
			return (p);
		p++;
	}
	return (0);
}
