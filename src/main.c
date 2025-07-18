/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: cde-migu <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/18 15:30:23 by cde-migu                      *    .     */
/*   Updated: 2025/07/18 18:07:23 by cde-migu       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_game	*init_game(t_gctrl *gctrl)
{
	t_game	*game;

	game = gctrl_malloc(gctrl, PROG_BLOCK, sizeof(t_game));
	game.map.grid = gctrl_malloc(gctrl, PROG_BLOCK, 32 * sizeof(char *));

	{
		int fd = open("maps/dev.cub", O_RDONLY);
		for (int i = 0; i < 32; i++)
			game.map.grid[i] = get_next_line(fd);
		game.map.height = 32;
		game.map.width = 32;
		game.map.floor_color = 0xB00B69;
		game.map.ceiling_color = 0x69B00B;
		close (fd);
	}

	game.player.x = 16;
	game.player.y = 16;
	game.player.dir = 0;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);

	game.base_img.img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);

	game.base_img.img_addr = mlx_get_data_addr(game.base_img.img, &game.base_img.bpp, &game.base_img.l_len, &game.base_img.endian);

	return (game);
}

int main(void)
{
	t_gctrl	*gctrl;
	t_game	*game;

	gctrl = gctrl_init();
	game = init_game(gctrl);//habrá que actualizarla con las cosas del parseo bien :)
}
