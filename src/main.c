/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: cde-migu <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/18 15:30:23 by cde-migu                      *    .     */
/*   Updated: 2025/08/07 15:48:13 by luna           tortolitas       .        */
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

int	main(int argn, char **argv)
{
	t_gctrl	*gctrl;
	t_game	*game;

	if (argn != 2)
		return (0);
	gctrl = gctrl_init();
	game = init_game(gctrl, argv[1]);
	debug_texture_dump(game);
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
