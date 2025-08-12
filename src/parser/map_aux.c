/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   map_aux.c                                     *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: ldel-val <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/08/12 14:54:29 by ldel-val                      *    .     */
/*   Updated: 2025/08/12 15:02:44 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_line_valid_map_section(const char *line)
{
	if (line == NULL)
		return (0);
	while (*line == ' ')
		line++;
	if (*line == '1')
		return (1);
	return (0);
}

int	get_angle_from_tile(char tile)
{
	if (tile == 'E')
		return (0);
	if (tile == 'S')
		return (90);
	if (tile == 'W')
		return (180);
	return (270);
}

int	is_player_tile(char tile)
{
	if (tile == 'N')
		return (1);
	if (tile == 'S')
		return (1);
	if (tile == 'E')
		return (1);
	if (tile == 'W')
		return (1);
	return (0);
}

char	char_to_tile(t_game *game, char c, int i)
{
	if (is_player_tile(c))
	{
		game->player.x = i;
		game->player.dir = get_angle_from_tile(c);
		return (TILE_FLOOR);
	}
	if (c == '1')
		return (TILE_WALL);
	if (c == '0')
		return (TILE_FLOOR);
	if (c == ' ' || c == '\n')
		return (TILE_EMPTY);
	return (TILE_ERROR);
}
