/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   map.c                                         *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/28 16:35:17 by luna                          *    .     */
/*   Updated: 2025/07/28 20:45:48 by luna           tortolitas       .        */
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

void	scan_map(t_file_content file, t_game *game)
{
	char	**start;
	char	**end;
	int		i;

	start = file.content;
	while (*start != NULL && !is_line_valid_map_section(*start))
		start++;
	end = start;
	while (*end != NULL && is_line_valid_map_section(*end))
		end++;
	game->map.grid = gctrl_malloc(game->gctrl, PROG_BLOCK,
			sizeof(char *) * (1 + end - start));
	i = 0;
	while (start < end)
	{
		game->map.grid[i] = ft_strdup(*start);
		gctrl_track_ptr(game->gctrl, game->map.grid[i], PROG_BLOCK);
		start++;
		i++;
	}
	game->map.width = 16;
	game->map.height = 16;
	game->player.x = 8;
	game->player.y = 8;
}
/* esta función me gustaría rehacerla, no es muy legible y es un poco dificil */
/* ponerle control de errores tal y como está hecha */
