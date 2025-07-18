/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:41:15 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/13 12:25:57 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;

	if (!s || !f)
		return ;
	count = 0;
	while (*s)
	{
		f(count, s);
		s++;
		count++;
	}
}
/*
void	f(unsigned int i, char	*s)
{
	if(ft_isalpha((int)*s))
		*s -= 32;
}
#include <stdio.h>
int	main(void)
{
	char	str[] = "hola a todos\n";

	printf("antes: %s", str);

	ft_striteri(str, f);
	printf("después: %s", str);
}
*/