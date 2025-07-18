/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:26:45 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/13 10:44:54 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n && (s1[x] != '\0' || s2[x] != '\0'))
	{
		if (s1[x] != s2[x])
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		x++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    const char *str1 = "t0";
    const char *str2 = "test\0";
    unsigned long n = 6;  // Number of characters to compare

    int result = ft_strncmp(str1, str2, n);
    printf("ft_strncmp result: %d\n", result);

    int original = strncmp(str1, str2, n);
    printf("strncmp result: %d\n", original);

    return 0;
}
*/
