/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   player_movement.c                             *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <ldel-val@student.42madrid.com>   (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/12 14:52:55 by ldel-val                      *    .     */
/*   Updated: 2025/08/12 14:53:24 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	move_player_forward(t_game *game)
{
	float	dx;
	float	dy;

	dx = cos(deg_to_rad(game->player.dir)) * 0.01;
	dy = sin(deg_to_rad(game->player.dir)) * 0.01;
	if (!check_collision(game, game->player.x + dx, game->player.y + dy))
	{
		game->player.x += dx;
		game->player.y += dy;
	}
}

void	move_player_backwards(t_game *game)
{
	float	dx;
	float	dy;

	dx = cos(deg_to_rad(game->player.dir)) * 0.01;
	dy = sin(deg_to_rad(game->player.dir)) * 0.01;
	if (!check_collision(game, game->player.x - dx, game->player.y - dy))
	{
		game->player.x -= dx;
		game->player.y -= dy;
	}
}

void	move_player_left(t_game *game)
{
	float	dx;
	float	dy;

	dx = cos(deg_to_rad(game->player.dir)) * 0.01;
	dy = sin(deg_to_rad(game->player.dir)) * 0.01;
	if (!check_collision(game, game->player.x + dy, game->player.y - dx))
	{
		game->player.x += dy;
		game->player.y -= dx;
	}
}

void	move_player_right(t_game *game)
{
	float	dx;
	float	dy;

	dx = cos(deg_to_rad(game->player.dir)) * 0.01;
	dy = sin(deg_to_rad(game->player.dir)) * 0.01;
	if (!check_collision(game, game->player.x - dy, game->player.y + dx))
	{
		game->player.x -= dy;
		game->player.y += dx;
	}
}
