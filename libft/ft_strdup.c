/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:00:11 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/13 12:19:59 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ptr = (char *)ft_calloc(len, sizeof(char));
	if (ptr == 0)
		return (0);
	ft_strlcpy(ptr, s1, len);
	return (ptr);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void) {
	const char *original_str = "";

	// Probando ft_strdup
	char *custom_strdup_result = ft_strdup(original_str);
	printf("Custom ft_strdup result: %s\n", custom_strdup_result);

	// Probando strdup original
	char *original_strdup_result = strdup(original_str);
	printf("Original strdup result: %s\n", original_strdup_result);

	// Comparando resultados
	if (strcmp(custom_strdup_result, original_strdup_result) == 0) {
		printf("¡La implementación de ft_strdup es correcta!\n");
	} else {
		printf("Error: La implementación de ft_strdup es incorrecta.\n");
	}

	// Liberando memoria
	free(custom_strdup_result);
	free(original_strdup_result);

	return (0);
}
*/