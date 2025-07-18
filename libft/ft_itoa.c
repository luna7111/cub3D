/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:36 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/11 18:28:28 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	i;

	i = 0;
	if (n < 1)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*fill_str(long n, char *s, int len)
{
	s[len] = '\0';
	len--;
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	nbr;

	nbr = (long)n;
	count = count_digits(nbr);
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (0);
	fill_str(nbr, str, count);
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*res;

	res = ft_itoa(14);
	printf("%s", res);
	free(res);
	return (0);
}
*/
