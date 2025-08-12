/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/28 20:22:35 by luna                          *    .     */
/*   Updated: 2025/08/12 15:08:46 by ldel-val       tortolitas       .        */
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
