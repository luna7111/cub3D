/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:48:09 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/30 21:21:48 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static char	*onlynull(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	if (!str)
		return (0);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			s_len;

	if (len == 0)
		return (onlynull());
	s_len = ft_strlen(s);
	if (start > s_len)
		return (onlynull());
	if (len > s_len - start)
		len = s_len - start;
	if (!s)
		return (0);
	str = (char *)malloc((len +1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len +1);
	return (str);
}

/*
#include <stdio.h>
int		main(int argc, const char *argv[])
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*strsub;
	int		arg;

	printf("%s\n", ft_substr(str, 0, 10));
}*/
