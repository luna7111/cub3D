/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:11:16 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/13 11:09:21 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*ptr;

	ptr = b;
	count = 0;
	while (count < len)
	{
		*ptr = (unsigned char)c;
		count++;
		ptr++;
	}
	return (b);
}
/*
int main(void)
{
    char str[] = "Hello, world!";
    char buffer[20];

    printf("Resultado de memset: %s\n", memset(buffer, 'A', 10));

    printf("Resultado de ft_memset: %s\n", ft_memset(buffer, 'A', 10));

    return 0;
}
*/