/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   graphics.c                                    *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/12 15:05:35 by ldel-val                      *    .     */
/*   Updated: 2025/08/12 15:22:11 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	game->base_img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->base_img.is_set = 1;
	game->base_img.addr = mlx_get_data_addr(game->base_img.img,
			&game->base_img.bpp, &game->base_img.l_len, &game->base_img.endian);
}
