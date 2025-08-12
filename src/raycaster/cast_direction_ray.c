/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   cast_direction_ray.c                          *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <ldel-val@student.42madrid.com>   (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/12 15:13:03 by ldel-val                      *    .     */
/*   Updated: 2025/08/12 15:13:57 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_collision	cast_row_ray_down(t_game *game, float dx, float dy)
{
	t_collision	collision;
	float		x;
	float		y;
	int			orientation_correction;

	dx = dx / fabs(dy);
	dy = 1;
	y = (int)game->player.y + 1;
	x = game->player.x + (dx * fabs(game->player.y - y));
	collision.direction = NORTH;
	orientation_correction = 0;
	while (!check_collision(game, x, y + orientation_correction))
	{
		x += dx;
		y += dy;
	}
	collision.dist = sqrt(sqr(x - game->player.x) + sqr(y - game->player.y));
	collision.offset = x - (int)x;
	return (collision);
}

t_collision	cast_row_ray_up(t_game *game, float dx, float dy)
{
	t_collision	collision;
	float		x;
	float		y;
	int			orientation_correction;

	dx = dx / fabs(dy);
	dy = -1;
	y = (int)game->player.y;
	x = game->player.x + (dx * fabs(game->player.y - y));
	collision.direction = SOUTH;
	orientation_correction = -1;
	while (!check_collision(game, x, y + orientation_correction))
	{
		x += dx;
		y += dy;
	}
	collision.dist = sqrt(sqr(x - game->player.x) + sqr(y - game->player.y));
	collision.offset = x - (int)x;
	return (collision);
}

t_collision	cast_column_ray_right(t_game *game, float dx, float dy)
{
	t_collision	collision;
	float		x;
	float		y;

	dy = dy / fabs(dx);
	dx = 1;
	collision.direction = WEST;
	x = (int)game->player.x + 1;
	y = game->player.y + (dy * fabs(game->player.x - x));
	while (!check_collision(game, x, y))
	{
		x += dx;
		y += dy;
	}
	collision.dist = sqrt(sqr(x - game->player.x) + sqr(y - game->player.y));
	collision.offset = y - (int)y;
	return (collision);
}

t_collision	cast_column_ray_left(t_game *game, float dx, float dy)
{
	t_collision	collision;
	float		x;
	float		y;

	dy = dy / fabs(dx);
	dx = -1;
	collision.direction = EAST;
	x = (int)game->player.x;
	y = game->player.y + (dy * fabs(game->player.x - x));
	while (!check_collision(game, x - 1, y))
	{
		x += dx;
		y += dy;
	}
	collision.dist = sqrt(sqr(x - game->player.x) + sqr(y - game->player.y));
	collision.offset = y - (int)y;
	return (collision);
}
