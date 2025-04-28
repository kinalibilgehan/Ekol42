#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	get_total_len(int size, char **strs, char *sep)
{
	int	total;
	int		i;
	int	sep_len;

	total = 0;
	i = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
		total += sep_len * (size - 1);
	total += 1;
	return (total);
}

char	*copy_string_segment(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char	*copy_sep_segment(char *dest, char *sep)
{
	while (*sep != '\0')
	{
		*dest = *sep;
		dest++;
		sep++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined_str;
	char	*start;
	int	total_len;
	int		i;

	if (size <= 0)
	{
		joined_str = (char *)malloc(1);
		if (joined_str == NULL)
			return (NULL);
		*joined_str = '\0';
		return (joined_str);
	}
	total_len = get_total_len(size, strs, sep);
	joined_str = (char *)malloc(total_len);
	if (joined_str == NULL)
		return (NULL);
	start = joined_str;
	i = 0;
	while (i < size)
	{
		joined_str = copy_string_segment(joined_str, strs[i]);
		if (i < size - 1)
			joined_str = copy_sep_segment(joined_str, sep);
		i++;
	}
	*joined_str = '\0';
	return (start);
}
