/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   textures.c                                    *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/12 15:15:37 by ldel-val                      *    .     */
/*   Updated: 2025/08/12 15:35:01 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	**get_missing_texture(t_game *game)
{
	char	**xpm;

	xpm = gctrl_malloc(game->gctrl, MISSING_TEXTURE_XPM, sizeof(char *) * 5);
	xpm[0] = ft_strdup("2 2 2 1");
	xpm[1] = ft_strdup(". c #000000");
	xpm[2] = ft_strdup("# c #f800f8");
	xpm[3] = ft_strdup(".#");
	xpm[4] = ft_strdup("#.");
	return (xpm);
}

int	map_pixel_from_texture(t_img texture,
		t_collision collision, float vertical_offset)
{
	int	color;
	int	position_x;
	int	position_y;

	position_x = texture.width * collision.offset;
	position_y = texture.height * vertical_offset;
	color = *(unsigned int *)(texture.addr + (position_y * texture.l_len)
			+ (position_x * (texture.bpp / 8)));
	return (color);
}

t_img	set_texture(t_game *game, t_cardinal_point direction)
{
	t_img	texture;

	if (direction == NORTH)
		texture = game->north;
	else if (direction == SOUTH)
		texture = game->south;
	else if (direction == EAST)
		texture = game->east;
	else
		texture = game->west;
	return (texture);
}
