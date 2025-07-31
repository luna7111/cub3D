/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   safe_exit.c                                   *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/31 19:18:59 by ldel-val                      *    .     */
/*   Updated: 2025/07/31 19:30:49 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	safe_exit(t_game *game)
{
	if (game->north.is_set == 1)
		mlx_destroy_image(game->north.img);
	if (game->south.is_set == 1)
		mlx_destroy_image(game->south.img);
	if (game->easr.is_set == 1)
		mlx_destroy_image(game->east.img);
	if (game->west.is_set == 1)
		mlx_destroy_image(game->west.img);
	if (game->base_img.is_set == 1)
		mlx_destroy_image(game->base_img.img);
}
