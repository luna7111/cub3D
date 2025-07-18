/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:38:38 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/23 16:25:56 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		*ptr = 0;
		count++;
		ptr++;
	}
}

/*
#include <string.h>
#include <stdio.h>
int main() {
    char original_str[] = "Original String";
    char custom_str[] = "Custom String";

    // Mostrar el contenido original antes de usar bzero o ft_bzero
    printf("Original String: %s\n", original_str);
    printf("Custom String  : %s\n", custom_str);

    // Usar bzero en el primer string
    bzero(original_str, sizeof(original_str));
    printf("\nAfter bzero:\n");
    printf("Original String: %s\n", original_str);

    // Usar ft_bzero en el segundo string
    ft_bzero(custom_str, sizeof(custom_str));
    printf("\nAfter ft_bzero:\n");
    printf("Custom String  : %s\n", custom_str);

    return 0;
}
*/