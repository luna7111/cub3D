/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   mlx_hooks.c                                   *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/07 13:24:39 by luna                          *    .     */
/*   Updated: 2025/08/10 17:52:55 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define K_ESC 65307

#define K_LEFT 65361
#define K_UP 65362
#define K_RIGHT 65363
#define K_DOWN 65364

#define K_W 119
#define K_A 97
#define K_S 115
#define K_D 100

#define ON_KEYDOWN 2
#define ON_KEYUP 3
#define ON_DESTROY 17

#define NO_EVENT_MASK 0
#define KEY_PRESS_MASK 1L
#define KEY_RELEASE_MASK 1L<<1

int		key_press_hook(int keycode, t_game *game)
{
	(void)game;
	if (keycode == K_UP)
		printf("UP pressed: %d\n", keycode);
	else if (keycode == K_DOWN)
		printf("DOWN pressed: %d\n", keycode);
	else if (keycode == K_LEFT)
		printf("LEFT pressed: %d\n", keycode);
	else if (keycode == K_RIGHT)
		printf("RIGHT pressed: %d\n", keycode);
	else if (keycode == K_W)
		printf("W pressed: %d\n", keycode);
	else if (keycode == K_A)
		printf("A pressed: %d\n", keycode);
	else if (keycode == K_S)
		printf("S pressed: %d\n", keycode);
	else if (keycode == K_D)
		printf("D pressed: %d\n", keycode);
	else if (keycode == K_ESC)
		safe_exit(game);
	else
		printf("key pressed: %d\n", keycode);
	return (0);
}

int		key_release_hook(int keycode, t_game *game)
{
	(void)game;
	if (keycode == K_UP)
		printf("UP released: %d\n", keycode);
	else if (keycode == K_DOWN)
		printf("DOWN released: %d\n", keycode);
	else if (keycode == K_LEFT)
		printf("LEFT released: %d\n", keycode);
	else if (keycode == K_RIGHT)
		printf("RIGHT released: %d\n", keycode);
	else if (keycode == K_W)
		printf("W released: %d\n", keycode);
	else if (keycode == K_A)
		printf("A released: %d\n", keycode);
	else if (keycode == K_S)
		printf("S released: %d\n", keycode);
	else if (keycode == K_D)
		printf("D released: %d\n", keycode);
	else if (keycode == K_ESC)
		safe_exit(game);
	else
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
	/* mlx_do_key_autorepeatoff(game->mlx); */
	/* puede que esto sea innecesario, además es una solución un poco cutre, */
	/* lo he añadido porque no quiero que se me olvide probar la diferencia en algún */
	/* PC malillo en el campus pero probablemente no haga falta */
	mlx_hook(game->win, ON_DESTROY, NO_EVENT_MASK, safe_exit, game);
	mlx_hook(game->win, ON_KEYDOWN, KEY_PRESS_MASK, key_press_hook, game);
	mlx_hook(game->win, ON_KEYUP, KEY_RELEASE_MASK, key_release_hook, game);
	mlx_loop_hook(game->mlx, move_player, game);
}
