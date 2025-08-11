/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: cde-migu <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/18 15:30:23 by cde-migu                      *    .     */
/*   Updated: 2025/08/11 14:48:13 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#include <stdio.h>
void	debug_texture_dump(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (game->north.is_set == 1 && game->north.error == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->north.img, 0, 0);
	if (game->south.is_set == 1 && game->south.error == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->south.img, 128, 0);
	if (game->east.is_set == 1 && game->east.error == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->east.img, 256, 0);
	if (game->west.is_set == 1 && game->west.error == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->west.img, 384, 0);
	while (y < 258)
	{
		while (x < 258)
		{
			if (game->map.grid[(y * game->map.height) / 258][(x * game->map.width) / 258] == TILE_WALL)
				mlx_pixel_put(game->mlx, game->win, 128 + x, 128 + y, 0xFFFFFF);
			else if (game->map.grid[(y * game->map.height) / 259][(x * game->map.width) / 258] == TILE_FLOOR)
				mlx_pixel_put(game->mlx, game->win, 128 + x, 128 + y, 0xAAAAAA);
			if (x * game->map.width / 258 == (size_t)game->player.x)
				if (y * game->map.height / 258 == (size_t)game->player.y)
				mlx_pixel_put(game->mlx, game->win, 128 + x, 128 + y, 0xFF0000);
			x++;
		}
		y++;
		x = 0;
	}
	x = 0;
	y = 0;
	while (y < 64)
	{
		while (x < 64)
		{
			mlx_pixel_put(game->mlx, game->win, x, 128 + y,
				game->map.ceiling_color);
			mlx_pixel_put(game->mlx, game->win, x, 192 + y,
				game->map.floor_color);
			x++;
		}
		x = 0;
		y++;
	}
	printf("Player position: x = %f y = %f Player direction: %f\n", game->player.x, game->player.y, game->player.dir);
}

float	deg_to_rad(float degrees)
{
	return (degrees * M_PI / 180);
}

float	sqr(float number)
{
	return (number * number);
}

bool	check_colission(t_game *game, float x, float y)
{
	int rounded_x;
	int rounded_y;

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

void	draw_vertical_section(t_game *game, int x, t_collision collision)
{
	int	section_size;
	int start_height;
	int i;
	int color;

	if (collision.direction == NORTH)
		color = 0x005500;
	else if (collision.direction == SOUTH)
		color = 0x005555;
	else if (collision.direction == EAST)
		color = 0x000055;
	else
		color = 0x550000;
	/* esto es solo para hacer pruebas antes de gestionar las texturas bien */

	if (collision.dist <= 0)
		collision.dist = 0.01;
	section_size = WIN_HEIGHT * 2 / collision.dist;
	start_height = (WIN_HEIGHT - section_size) / 2;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		if (i < start_height)
			mlx_pixel_put(game->mlx, game->win, x, i, game->map.ceiling_color);
		else if (i < start_height + section_size)
			mlx_pixel_put(game->mlx, game->win, x, i, color);
		else
			mlx_pixel_put(game->mlx, game->win, x, i, game->map.floor_color);
		i++;
	}
}
/* "que vino primero, la polla o la cebolla?" - Said Carol - Michael Scott */

t_collision	cast_row_ray(t_game *game, float dx, float dy)
{
	t_collision collision;
	float		x;
	float		y;

	dx = dx / fabs(dy);
	if (dy > 0)
		dy = 1;
	else 
		dy = -1;

	if (dy > 0)
		y = (int)game->player.y + 1;
	else
		y = (int)game->player.y;
	x = game->player.x + (dx * fabs(game->player.y - y));

	if (dy > 0)
	{
		collision.direction = NORTH;
		while (!check_colission(game, x, y))
		{
			x += dx;
			y += dy;
		}
	}
	else
	{
		collision.direction = SOUTH;
		while (!check_colission(game, x, y - 1))
		{
			x += dx;
			y += dy;
		}
	}
	collision.dist = sqrt(sqr(x - game->player.x) + sqr(y - game->player.y));
	return (collision);
}

t_collision	cast_column_ray(t_game *game, float dx, float dy)
{
	t_collision collision;
	float		x;
	float		y;

	dy = dy / fabs(dx);
	if (dx > 0)
		dx = 1;
	else 
		dx = -1;

	if (dx > 0)
		x = (int)game->player.x + 1;
	else
		x = (int)game->player.x;
	y = game->player.y + (dy * fabs(game->player.x - x));

	if (dx > 0)
	{
		collision.direction = WEST;
		while (!check_colission(game, x, y))
		{
			x += dx;
			y += dy;
		}
	}
	else
	{
		collision.direction = EAST;
		while (!check_colission(game, x - 1, y))
		{
			x += dx;
			y += dy;
		}
	}
	collision.dist = sqrt(sqr(x - game->player.x) + sqr(y - game->player.y));
	return (collision);
}


void	cast_ray(t_game *game, int ray_index, float ray_angle)
{
	t_collision	row_collision;
	t_collision	column_collision;
	float	dx;
	float	dy;

	dx = cos(deg_to_rad(ray_angle));

	row_collision = cast_row_ray(game, dx, dy);
	column_collision = cast_column_ray(game, dx, dy);

	if (row_collision.dist > column_collision.dist)
		draw_vertical_section(game, ray_index, column_collision);
	else
		draw_vertical_section(game, ray_index, row_collision);
}

void	draw_frame(t_game *game)
{
	int		i;
	float	fov_angle;
	float	ray_angle;

	i = 0;
	fov_angle = - FOV / 2;
	while (i < WIN_WIDTH)
	{
		fov_angle = (float)(-FOV / 2.0) + (((float)FOV / WIN_WIDTH) * i);
		ray_angle = (float)fov_angle + game->player.dir;
		cast_ray(game, i, ray_angle);
		i += 1;
	}
}

int	main(int argn, char **argv)
{
	t_gctrl	*gctrl;
	t_game	*game;

	if (argn != 2)
		return (0);
	gctrl = gctrl_init();
	game = init_game(gctrl, argv[1]);
	/* debug_texture_dump(game); */
	init_hooks(game);
	mlx_loop(game->mlx);
	safe_exit(game);
}
/*                     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ */
/*                   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ */
/*                   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ */
/*                   ▒▒██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒ */
/*                   ▒▒▒▒▒▒  ░░  ▒▒▒▒▒▒▒▒ */
/*                   ▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒ */
/*                   ▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒ */
/*                     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ */
/*                   ▓▓▒▒▓▓▒▒▒▒▒▒▒▒▓▓░░ */
/*                 ▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓░░ */
/*                 ▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░░░ */
/*                 ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░░░░░ */
/*               ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░▒▒░░░░ */
/*             ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░▒▒▒▒▒▒▒▒ */
/*             ▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒░░░░▒▒▒▒▒▒▒▒ */
/*             ▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▓▓▓▓▒▒ */
/*               ▒▒░░░░░░░░░░░░░░░░░░░░░░░░▓▓▒▒▒▒▓▓ */
/*                 ░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓▒▒ */
/*                 ░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░ */
/*                   ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ */
/*                       ░░░░░░░░░░░░░░░░░░░░░░░░ */
/* ▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓░░▓▓▒▒▓▓▒▒▓▓░░▓▓▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓▓▓▒▒▓▓▒▒ */
/*                       ░░          ░░░░▒▒░░▒▒░░ */
/*                                     ░░▒▒░░▒▒░░ */
/*                                     ░░▒▒░░▒▒░░ */
/*                                     ░░▒▒░░▒▒░░ */
/*                                       ▒▒░░▒▒ */
