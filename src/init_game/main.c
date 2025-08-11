/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/28 20:22:35 by luna                          *    .     */
/*   Updated: 2025/08/11 20:34:10 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_attributes_to_zero(t_game *game)
{
	game->north.is_set = 0;
	game->south.is_set = 0;
	game->east.is_set = 0;
	game->west.is_set = 0;
	game->base_img.is_set = 0;
	game->north.error = 0;
	game->south.error = 0;
	game->east.error = 0;
	game->west.error = 0;
	game->base_img.error = 0;
	game->map.floor_color = COLOR_UNSET;
	game->map.ceiling_color = COLOR_UNSET;
	game->player.input_left = 0;
	game->player.input_right = 0;
	game->player.input_w = 0;
	game->player.input_a = 0;
	game->player.input_s = 0;
	game->player.input_d = 0;
}

void	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	game->base_img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->base_img.is_set = 1;
	game->base_img.addr = mlx_get_data_addr(game->base_img.img,
			&game->base_img.bpp, &game->base_img.l_len, &game->base_img.endian);
}

char	**get_missing_texture(t_game *game)
{
	char	**xpm;

	xpm = gctrl_malloc(game->gctrl, MISSING_TEXTURE_XPM, sizeof(char *) * 5);
	xpm[0] = ft_strdup("2 2 2 1");
	xpm[1] = ft_strdup(". c #000000");
	xpm[2] = ft_strdup("# c #f800f8");
	xpm[3] = ft_strdup(".#");
	xpm[4] = ft_strdup("#.");
	return (xpm);
}

void	check_color_attribute(t_game *game, int *atribute,
		const char *atribute_name)
{
	if (*atribute == COLOR_UNSET)
	{
		printf("%s was not set, using default color instead.\n", atribute_name);
		*atribute = DEFAULT_COLOR;
		return ;
	}
	if (*atribute == COLOR_ERROR)
	{
		printf("%s: syntax error.\n", atribute_name);
		safe_exit(game);
	}
	(void)game;
}

void	check_texture(t_game *game, t_img *texture, const char *texture_name)
{
	if (texture->is_set == 0)
	{
		printf("%s was not set, using fallback texture.\n", texture_name);
		texture->is_set = 1;
		texture->img = mlx_xpm_to_image(game->mlx, get_missing_texture(game),
				&texture->width, &texture->height);
		texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
				&texture->l_len, &texture->endian);
		gctrl_cleanup(game->gctrl, MISSING_TEXTURE_XPM);
		return ;
	}
	if (texture->error == 1)
	{
		printf("%s: syntax error.\n", texture_name);
		safe_exit(game);
	}
}

void	check_map_content(t_game *game)
{
	if (game->map.height <= 0 || game->map.width <= 0)
	{
		printf("Empty map.\n");
		safe_exit(game);
	}
}

void	check_attributes(t_game *game)
{
	check_map_content(game);
	check_color_attribute(game, &game->map.ceiling_color, "Ceiling color");
	check_color_attribute(game, &game->map.floor_color, "Floor color");
	check_texture(game, &game->north, "North texture");
	check_texture(game, &game->south, "South texture");
	check_texture(game, &game->east, "East texture");
	check_texture(game, &game->west, "West texture");
}

t_game	*init_game(t_gctrl *gctrl, char *filename)
{
	t_game	*game;

	game = gctrl_malloc(gctrl, PROG_BLOCK, sizeof(t_game));
	game->gctrl = gctrl;
	init_attributes_to_zero(game);
	init_graphics(game);
	parse_file(gctrl, game, filename);
	check_attributes(game);
	if (check_map_borders(game) == 0)
	{
		printf("Error: open map.\n");
		safe_exit(game);
	}
	return (game);
}
