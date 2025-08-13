/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   drawing.c                                     *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <ldel-val@student.42madrid.com>   (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/12 15:17:05 by ldel-val                      *    .     */
/*   Updated: 2025/08/13 14:04:12 by luna           tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_pixel(t_game *game, int x, int y, int color)
{
	t_img	img;
	char	*img_addr;

	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	img = game->base_img;
	img_addr = img.addr;
	img_addr += y * img.l_len + x * (img.bpp / 8);
	*(unsigned int *)img_addr = color;
}

void	draw_vertical_section(t_game *game, int x, t_collision collision)
{
	int		section_size;
	int		start_height;
	int		i;
	t_img	texture;

	if (collision.direction == NORTH || collision.direction == EAST)
		collision.offset = 1 - collision.offset;
	if (collision.dist == 0)
		collision.dist = 0.0001;
	texture = set_texture(game, collision.direction);
	section_size = WIN_HEIGHT * 2 / collision.dist;
	start_height = (WIN_HEIGHT - section_size) / 2;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		if (i < start_height)
			put_pixel(game, x, i, game->map.ceiling_color);
		else if (i < start_height + section_size)
			put_pixel(game, x, i, map_pixel_from_texture(texture, collision,
					(float)(i - start_height) / section_size));
		else
			put_pixel(game, x, i, game->map.floor_color);
		i++;
	}
}
