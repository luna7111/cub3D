/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:45:40 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/27 18:43:43 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c;

	c = 0;
	if (dstsize > 0)
	{
		while (c < dstsize - 1 && src[c] != '\0')
		{
			dst[c] = src[c];
			c++;
		}
		dst[c] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char		*original = "Hello, world!";
	char			destination[20];
	unsigned long	result;
	char			standardDestination[20];
	size_t			standardResult;

	// Test strings
	// Test your ft_strlcpy
	result = ft_strlcpy(destination, original, sizeof(destination));
	printf("ft_strlcpy result: %lu, destination: %s\n", result, destination);
	// Test the standard strlcpy
	standardResult = strlcpy(standardDestination, original,
			sizeof(standardDestination));
	printf("strlcpy result: %zu, destination: %s\n", standardResult,
		standardDestination);
	// Compare the results
	if (result == standardResult && strcmp(destination,
			standardDestination) == 0)
	{
		printf("Test passed! ft_strlcpy matches strlcpy.\n");
	}
	else
	{
		printf("Test failed! ft_strlcpy does not match strlcpy.\n");
	}
	return (0);
}
*/

/*
	gcc -c ft_strlen.c -o ft_strlen.o
	gcc -c ft_strlcpy.c -o ft_strlcpy.o

	gcc ft_strlen.o ft_strlcpy.o -o myprogram
	./myprogram
*/
