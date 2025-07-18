/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:44:06 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/30 19:02:23 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(const void *dst, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			count;

	if (!dst && !src)
		return (0);
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	count = 0;
	while (count < n)
	{
		destination[count] = source[count];
		count++;
	}
	return ((void *)dst);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello, World!";
	char	dst[20];

	ft_memcpy(dst, src, 11);
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dst);
	return (0);
}
*/