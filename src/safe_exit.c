/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   safe_exit.c                                   *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/31 19:18:59 by ldel-val                      *    .     */
/*   Updated: 2025/07/31 20:03:29 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	safe_exit(t_game *game)
{
	if (game->north.is_set == 1)
		mlx_destroy_image(game->mlx, game->north.img);
	if (game->south.is_set == 1)
		mlx_destroy_image(game->mlx, game->south.img);
	if (game->east.is_set == 1)
		mlx_destroy_image(game->mlx, game->east.img);
	if (game->west.is_set == 1)
		mlx_destroy_image(game->mlx, game->west.img);
	if (game->base_img.is_set == 1)
		mlx_destroy_image(game->mlx, game->base_img.img);
	gctrl_terminate(game->gctrl);
}
