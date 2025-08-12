/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   aux.c                                         *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <ldel-val@student.42madrid.com>   (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/12 14:50:05 by ldel-val                      *    .     */
/*   Updated: 2025/08/12 14:58:05 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	deg_to_rad(float degrees)
{
	return (degrees * M_PI / 180);
}

float	sqr(float number)
{
	return (number * number);
}

bool	check_collision(t_game *game, float x, float y)
{
	int	rounded_x;
	int	rounded_y;

	rounded_x = (int)x;
	rounded_y = (int)y;
	if (rounded_x < 0 || rounded_x > (int)game->map.width)
		return (1);
	if (rounded_y < 0 || rounded_y > (int)game->map.height)
		return (1);
	if (game->map.grid[rounded_y][rounded_x] == TILE_FLOOR)
		return (0);
	return (1);
}
