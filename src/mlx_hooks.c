/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   mlx_hooks.c                                   *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/07 13:24:39 by luna                          *    .     */
/*   Updated: 2025/08/11 20:51:15 by ldel-val       tortolitas       .        */
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
	if (keycode == K_LEFT)
		game->player.input_left = true;
	else if (keycode == K_RIGHT)
		game->player.input_right = true;
	else if (keycode == K_W)
		game->player.input_w = true;
	else if (keycode == K_A)
		game->player.input_a = true;
	else if (keycode == K_S)
		game->player.input_s = true;
	else if (keycode == K_D)
		game->player.input_d = true;
	else if (keycode == K_ESC)
		safe_exit(game);
	return (0);
}

int		key_release_hook(int keycode, t_game *game)
{
	if (keycode == K_LEFT)
		game->player.input_left = false;
	else if (keycode == K_RIGHT)
		game->player.input_right = false;
	else if (keycode == K_W)
		game->player.input_w = false;
	else if (keycode == K_A)
		game->player.input_a = false;
	else if (keycode == K_S)
		game->player.input_s = false;
	else if (keycode == K_D)
		game->player.input_d = false;
	return (0);
}

int		main_loop(t_game *game)
{
	float dx = cos(deg_to_rad(game->player.dir)) * 0.01;
	float dy = sin(deg_to_rad(game->player.dir)) * 0.01;

	if (game->player.input_left == true)
		game->player.dir -= 0.2;
	if (game->player.input_right == true)
		game->player.dir += 0.2;
	if (game->player.input_w == true && !check_collision(game, game->player.x + dx, game->player.y + dy))
	{
		game->player.x += dx;
		game->player.y += dy;
	}
	if (game->player.input_s == true && !check_collision(game, game->player.x - dx, game->player.y - dy))
	{
		game->player.x -= dx;
		game->player.y -= dy;
	}
	if (game->player.input_a == true && !check_collision(game, game->player.x + dy, game->player.y - dx))
	{
		game->player.x += dy;
		game->player.y -= dx;
	}
	if (game->player.input_d == true && !check_collision(game, game->player.x - dy, game->player.y + dx))
	{
		game->player.x -= dy;
		game->player.y += dx;
	}
	if (game->player.dir > 360)
		game->player.dir -= 360;
	else if (game->player.dir < 0)
		game->player.dir += 360;
	draw_frame(game);
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
	mlx_loop_hook(game->mlx, main_loop, game);
}
