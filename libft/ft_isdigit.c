/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:40:31 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/06 12:29:06 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d", isdigit(50));
	printf("%d", ft_isdigit(50));
	return (0);
}
*/
