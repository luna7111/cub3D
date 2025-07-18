/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:34:03 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/13 11:04:14 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*pt_s;
	size_t			i;

	ch = (unsigned char)c;
	pt_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (pt_s[i] == ch)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	 const char *str = "Hello, world!";
    int c = 'w';
    size_t n = strlen(str);

    void *original_result = memchr(str, c, n);

    void *custom_result = ft_memchr(str, c, n);
}
*/
