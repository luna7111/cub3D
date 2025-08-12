/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   ft_str_coincidence.c                          *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <ldel-val@student.42madrid.com>       (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/29 19:29:32 by luna                          *    .     */
/*   Updated: 2025/08/12 15:51:19 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_str_coincidence(char const *s, int (*f)(char))
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (f(s[i]) == 1)
			return (1);
		i ++;
	}
	return (0);
}
