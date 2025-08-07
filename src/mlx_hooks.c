/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   mlx_hooks.c                                   *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/07 13:24:39 by luna                          *    .     */
/*   Updated: 2025/08/07 15:38:19 by luna           tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define K_ESC 65307

int		key_press_hook(int keycode, t_game *game)
{
	(void)game;
	printf("key pressed: %d\n", keycode);
	if (keycode == K_ESC)
		safe_exit(game);
	return (0);
}

int		key_release_hook(int keycode, t_game *game)
{
	(void)game;
	printf("key released: %d\n", keycode);
	return (0);
}

int		move_player(t_game *game)
{
	(void)game;
	return (0);
}

void init_hooks(t_game *game)
{
	mlx_do_key_autorepeatoff(game->mlx);
	mlx_hook(game->win, 2, 1, key_press_hook, game);
	mlx_hook(game->win, 3, 1L << 1, key_release_hook, game);
	mlx_loop_hook(game->mlx, move_player, game);
}
