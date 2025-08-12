/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   checks.c                                      *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/12 15:07:01 by ldel-val                      *    .     */
/*   Updated: 2025/08/12 15:09:07 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
