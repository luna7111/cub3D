/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:13:17 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/06 12:27:44 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d", isalnum(78));
	printf("%d", ft_isalnum(78));
	return (0);
}

gcc -c ft_isalpha.c -o ft_isalpha.o
gcc -c ft_isdigit.c -o ft_isdigit.o
gcc -c ft_isalnum.c -o ft_isalnum.o

gcc ft_isalpha.o ft_isdigit.o ft_isalnum.o -o my_program

./my_program
*/