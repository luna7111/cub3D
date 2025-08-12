/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   map.c                                         *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/28 16:35:17 by luna                          *    .     */
/*   Updated: 2025/08/12 14:55:43 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*get_map_line(t_game *game, char *raw_line)
{
	char	*line;
	size_t	raw_length;
	size_t	i;

	line = gctrl_malloc(game->gctrl, PROG_BLOCK,
			sizeof(char) * (game->map.width + 1));
	i = 0;
	raw_length = ft_strlen(raw_line);
	while (i < raw_length)
	{
		line[i] = char_to_tile(game, raw_line[i], i);
		if (line[i] == TILE_ERROR)
			return (NULL);
		i++;
	}
	while (i < game->map.width)
	{
		line[i] = TILE_EMPTY;
		i++;
	}
	line[i] = TILE_EMPTY;
	return (line);
}

size_t	get_map_dimensions(t_file_content file, t_game *game)
{
	size_t	start;
	size_t	end;
	size_t	width;

	start = 0;
	while (file.content[start] != NULL
		&& !is_line_valid_map_section(file.content[start]))
		start++;
	end = start;
	width = 0;
	while (file.content[end] != NULL)
	{
		if (ft_strlen(file.content[end]) > width)
			width = ft_strlen(file.content[end]);
		if (ft_str_coincidence(file.content[end], is_player_tile))
			game->player.y = end - start;
		end++;
	}
	game->map.height = end - start;
	game->map.width = width;
	return (start);
}

int	check_open_void(char **map, size_t x, size_t y)
{
	if (x == 0 || y == 0)
		if (map[y][x] == TILE_FLOOR)
			return (0);
	if (map[y][x] == TILE_FLOOR)
	{
		if (map[y - 1][x] == TILE_EMPTY)
			return (0);
		if (map[y + 1][x] == TILE_EMPTY)
			return (0);
		if (map[y][x - 1] == TILE_EMPTY)
			return (0);
		if (map[y][x + 1] == TILE_EMPTY)
			return (0);
	}
	return (1);
}

int	check_map_borders(t_game *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			if (!check_open_void(game->map.grid, x, y))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	scan_map(t_file_content file, t_game *game)
{
	size_t	start;
	size_t	i;

	start = get_map_dimensions(file, game);
	game->map.grid = gctrl_malloc(game->gctrl, PROG_BLOCK,
			sizeof(char *) * (game->map.height + 1));
	i = 0;
	while (i < game->map.height)
	{
		game->map.grid[i] = get_map_line(game, file.content[start + i]);
		if (game->map.grid[i] == NULL)
		{
			printf("Error: unexpected character in map\n");
			safe_exit(game);
		}
		i++;
	}
	game->map.grid[i] = get_map_line(game, "");
}
/* esta función me gustaría rehacerla, no es muy legible y es un poco dificil */
/* ponerle control de errores tal y como está hecha */
