/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:41:39 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/13 10:50:34 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	char	*aux;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			j ++;
			if (needle[j] == '\0')
			{
				aux = (char *)&haystack[i];
				return (aux);
			}
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*haystack = "encuentra algo por aqui";
	char	*needle = "algo";
	size_t	len = 15;

	strnstr(haystack, needle, len);
	ft_strnstr(haystack, needle, len);

	return (0);
}
*/