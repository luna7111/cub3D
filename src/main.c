/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: cde-migu <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/18 15:30:23 by cde-migu                      *    .     */
/*   Updated: 2025/07/18 17:23:57 by cde-migu       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_game	*init_game(t_gctrl *gctrl)
{
	t_game	*game;

	game = gctrl_malloc(gctrl, PROG_BLOCK, sizeof(t_game));
	game.map.grid = gctrl_malloc(gctrl, PROG_BLOCK, 32 * sizeof(char *));

	int fd = open("maps/dev.cub", O_RDONLY);
	for (int i = 0; i < 32; i++)
		map[i] = get_next_line(fd);

	return (game);
}

int main(void)
{
	t_gctrl	*gctrl;
	t_game	*game;

	gctrl = gctrl_init();
	game = init_game(gctrl);//habrá que actualizarla con las cosas del parseo bien :)
}
