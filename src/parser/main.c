/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/28 17:12:00 by luna                          *    .     */
/*   Updated: 2025/08/11 22:00:51 by luna           tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	player_ocurrences(const char *line)
{
	int	ocurrences;

	ocurrences = 0;
	while (*line != '\n' && *line != '\0')
	{
		if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
			ocurrences ++;
		line ++;
	}
	return (ocurrences);
}

bool	check_empty_map(t_file_content file)
{
	size_t	i;
	int		ocurrences;

	i = 0;
	ocurrences = 0;
	while (i < file.line_number)
	{
		if (ocurrences > 0 && !is_line_valid_map_section(file.content[i]))
			return (false);
		if (is_line_valid_map_section(file.content[i]))
			ocurrences ++;
		i++;
	}
	if (ocurrences <= 0)
		return (false);
	return (true);
}

bool	check_player(t_file_content file)
{
	size_t	i;
	int		ocurrences;

	i = 0;
	ocurrences = 0;
	while (i < file.line_number)
	{
		if (is_line_valid_map_section(file.content[i]))
			ocurrences += player_ocurrences(file.content[i]);
		if (ocurrences >= 2)
			return (false);
		i++;
	}
	if (ocurrences == 1)
		return (true);
	return (false);
}

void	parse_file(t_gctrl *gctrl, t_game *game, char *filename)
{
	t_file_content	file;

	file = load_file(gctrl, filename);
	if (file.error == 1)
	{
		printf("Error: invalid file.\n");
		safe_exit(game);
	}
	if (!check_empty_map(file))
	{
		printf("Error: invalid map.\n");
		safe_exit(game);
	}
	if (!check_attribute_repetition(file.content))
	{
		printf("Error: redefinition of the same attribute.\n");
		safe_exit(game);
	}
	if (!check_player(file))
	{
		printf("Error: wrong number of players.\n");
		safe_exit(game);
	}
	scan_atributes(file, game);
	scan_map(file, game);
}
