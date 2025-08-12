/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/12 15:10:18 by ldel-val                      *    .     */
/*   Updated: 2025/08/12 15:18:19 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_collision	cast_row_ray(t_game *game, float dx, float dy)
{
	if (dy > 0)
		return (cast_row_ray_down(game, dx, dy));
	return (cast_row_ray_up(game, dx, dy));
}

t_collision	cast_column_ray(t_game *game, float dx, float dy)
{
	if (dx > 0)
		return (cast_column_ray_right(game, dx, dy));
	return (cast_column_ray_left(game, dx, dy));
}

void	cast_ray(t_game *game, int ray_index, float ray_angle)
{
	t_collision	row_collision;
	t_collision	column_collision;
	t_collision	shortest_collision;
	float		dx;
	float		dy;

	dx = cos(deg_to_rad(ray_angle));
	dy = sin(deg_to_rad(ray_angle));
	row_collision = cast_row_ray(game, dx, dy);
	column_collision = cast_column_ray(game, dx, dy);
	if (row_collision.dist > column_collision.dist)
		shortest_collision = column_collision;
	else
		shortest_collision = row_collision;
	shortest_collision.dist *= cos(deg_to_rad(ray_angle - game->player.dir));
	draw_vertical_section(game, ray_index, shortest_collision);
}

void	draw_frame(t_game *game)
{
	int		i;
	float	fov_angle;
	float	ray_angle;

	i = 0;
	fov_angle = -FOV / 2;
	while (i < WIN_WIDTH)
	{
		fov_angle = (float)(-FOV / 2.0) + (((float)FOV / WIN_WIDTH) * i);
		ray_angle = (float)fov_angle + game->player.dir;
		cast_ray(game, i, ray_angle);
		i += 1;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->base_img.img, 0, 0);
}
