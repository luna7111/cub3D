/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:27:59 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/06 12:28:54 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d", isascii(138));
	printf("%d", ft_isascii(138));
	return (0);
}
*/