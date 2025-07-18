/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:20:14 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/03 13:40:16 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	int		count;
	char	*new_str;

	if (!s || !f)
		return (0);
	count = 0;
	len = ft_strlen(s);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (0);
	while (count < (int)len)
	{
		new_str[count] = f(count, s[count]);
		count++;
	}
	new_str[len] = '\0';
	return (new_str);
}
