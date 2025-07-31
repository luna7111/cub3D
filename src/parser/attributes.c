/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   attributes.c                                  *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/28 15:27:22 by luna                          *    .     */
/*   Updated: 2025/07/31 20:47:45 by ldel-val       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_img	get_texture_from_attribute(t_game *game, char *attribute_line)
{
	t_img	texture;
	char	*filename;

	texture.is_set = 1;
	filename = get_attribute_value(attribute_line);
	texture.img = mlx_xpm_file_to_image(game->mlx, filename, &texture.width,
			&texture.height);
	if (texture.img == NULL)
	{
		free(filename);
		return (texture.error = 1, texture);
	}
	texture.addr = mlx_get_data_addr(texture.img, &texture.bpp,
			&texture.l_len, &texture.endian);
	free(filename);
	return (texture.error = 0, texture);
}

int	get_color_from_attribute(t_game *game, char *attribute_line)
{
	int		color;
	char	*value;

	value = get_attribute_value(attribute_line);
	color = parse_rgb(value);
	free(value);
	(void)game;
	return (color);
}

void	scan_atributes(t_file_content file, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < file.line_number)
	{
		if (!ft_strncmp(file.content[i], "NO ", 3))
			game->north = get_texture_from_attribute(game, file.content[i]);
		else if (!ft_strncmp(file.content[i], "SO ", 3))
			game->south = get_texture_from_attribute(game, file.content[i]);
		else if (!ft_strncmp(file.content[i], "WE ", 3))
			game->west = get_texture_from_attribute(game, file.content[i]);
		else if (!ft_strncmp(file.content[i], "EA ", 3))
			game->east = get_texture_from_attribute(game, file.content[i]);
		else if (!ft_strncmp(file.content[i], "F ", 2))
			game->map.floor_color = get_color_from_attribute(game,
					file.content[i]);
		else if (!ft_strncmp(file.content[i], "C ", 2))
			game->map.ceiling_color = get_color_from_attribute(game,
					file.content[i]);
		i++;
	}
}
