/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:17:25 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/24 12:40:02 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = ft_strlen(dst);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len)
		return (dstsize + ft_strlen(src));
	while (j + 1 < dstsize && src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst_len + src_len);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void) {
	// Tamaño del búfer de destino
	unsigned long bufsize = 8;

	// Cadenas de prueba
	char dest1[20] = "Hola, ";
	char dest2[20] = "Hola, ";
	const char *src = "mundo!";

	// Llamada a ft_strlcat
	unsigned long result1 = ft_strlcat(dest1, src, bufsize);

	// Llamada a strlcat original
	unsigned long result2 = strlcat(dest2, src, bufsize);

	// Imprimir resultados
	printf("Resultado de ft_strlcat: %s (%lu)\n", dest1, result1);
	printf("Resultado de strlcat original: %s (%lu)\n", dest2, result2);

	// Comparar resultados
	if (strcmp(dest1, dest2) == 0 && result1 == result2) {
		printf("¡Las funciones coinciden!\n");
	} else {
		printf("¡Las funciones NO coinciden!\n");
	}

	return (0);
}
*/

/*
	gcc -c ft_strlen.c -o ft_strlen.o
	gcc -c ft_strlcat.c -o ft_strlcat.o

	gcc ft_strlen.o ft_strlcat.o -o myprogram
	./myprogram

	gcc ft_strlen.o ft_strlcat.o -o myprogram && ./myprogram
*/