/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: cde-migu <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/18 15:30:23 by cde-migu                      *    .     */
/*   Updated: 2025/07/28 16:19:44 by luna           tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	game->base_img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->base_img.addr = mlx_get_data_addr(game->base_img.img,
			&game->base_img.bpp, &game->base_img.l_len, &game->base_img.endian);
}
/* yo haría una función para inicializar una textura y pondría cuatro */
/* llamadas a esa función dentro de esta :) */

char	**get_missing_texture(t_game *game)
{
	char	**xpm;

	xpm = gctrl_malloc(game->gctrl, PROG_BLOCK, sizeof(char *) * 5);
	xpm[0] = ft_strdup("2 2 2 1");
	xpm[1] = ft_strdup(". c #000000");
	xpm[2] = ft_strdup("# c #f800f8");
	xpm[3] = ft_strdup(".#");
	xpm[4] = ft_strdup("#.");
	return (xpm);
}

int	is_line_valid_map_section(const char *line)
{
	if (line == NULL)
		return (0);
	while (*line == ' ')
		line++;
	if (*line == '1')
		return (1);
	return (0);
}

void	scan_map(t_file_content file, t_game *game)
{
	char	**start;
	char	**end;
	int		i;

	start = file.content;
	while (*start != NULL && !is_line_valid_map_section(*start))
		start++;
	end = start;
	while (*end != NULL && is_line_valid_map_section(*end))
		end++;
	game->map.grid = gctrl_malloc(game->gctrl, PROG_BLOCK,
			sizeof(char *) * (1 + end - start));
	i = 0;
	while (start < end)
	{
		game->map.grid[i] = ft_strdup(*start);
		gctrl_track_ptr(game->gctrl, game->map.grid[i], PROG_BLOCK);
		start++;
		i++;
	}
	game->map.width = 16;
	game->map.height = 16;
}

void	parse_file(t_gctrl *gctrl, t_game *game, char *filename)
{
	t_file_content	file;

	file = load_file(gctrl, filename);
	scan_atributes(file, game);
	scan_map(file, game);
}

t_game	*init_game(t_gctrl *gctrl, char *filename)
{
	t_game	*game;

	game = gctrl_malloc(gctrl, PROG_BLOCK, sizeof(t_game));
	game->gctrl = gctrl;
	init_graphics(game);
	parse_file(gctrl, game, filename);
	return (game);
}
/* habrá que actualizarla con las cosas del parseo bien :) */

void	debug_texture_dump(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->north.img, 0,0);
	mlx_put_image_to_window(game->mlx, game->win, game->south.img, 128,0);
	mlx_put_image_to_window(game->mlx, game->win, game->east.img, 256,0);
	mlx_put_image_to_window(game->mlx, game->win, game->west.img, 384,0);
	int x = 0;
	int y = 0;
	while (y < 258) {
		
		while (x < 258) {
	
			if (game->map.grid[(x * game->map.width) / 258][(y * game->map.height) / 258] == '1')
				mlx_pixel_put(game->mlx, game->win, 128 + x, 128 + y, 0xFFFFFF);
			x++;
		}
		y++;
		x = 0;
	}
	x = 0;
	y = 0;
	while (y < 64) {
		while (x < 64) {
			mlx_pixel_put(game->mlx, game->win, x, 128 + y, game->map.ceiling_color);
			mlx_pixel_put(game->mlx, game->win, x, 192 + y, game->map.floor_color);
			x++;
		}
		x = 0;
		y++;
	}
}

int main(int argn, char **argv)
{
	t_gctrl	*gctrl;
	t_game	*game;

	if (argn != 2)
		return (0);
	gctrl = gctrl_init();
	game = init_game(gctrl, argv[1]);
	debug_texture_dump(game);
	mlx_loop(game->mlx);
	gctrl_terminate(gctrl);
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
