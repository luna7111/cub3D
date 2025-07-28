/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   attributes_aux.c                              *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/28 16:00:35 by luna                          *    .     */
/*   Updated: 2025/07/28 16:29:15 by luna           tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*get_attribute_value(const char *line)
{
	size_t	value_size;
	char	*value;

	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	value_size = 0;
	while (line[value_size] != '\n' && line[value_size] != ' ')
		value_size++;
	value = ft_substr(line, 0, value_size);
	return (value);
}

int	parse_comma_separated_number(char *str)
{
	int		value;

	value = 0;
	while (*str != ',' && *str != '\0' && *str != '\n')
	{
		if (*str > '9' || *str < '0')
			return (COLOR_ERROR);
		value *= 10;
		value += *str - '0';
		str++;
	}
	if (value > 255)
		return (COLOR_ERROR);
	return (value);
}

int	parse_rgb(char *rgb)
{
	int	red;
	int	green;
	int	blue;
	int	color;

	red = parse_comma_separated_number(rgb);
	while (*rgb != ',')
		rgb++;
	rgb++;
	green = parse_comma_separated_number(rgb);
	while (*rgb != ',')
		rgb++;
	rgb++;
	blue = parse_comma_separated_number(rgb);
	if (red == COLOR_ERROR || green == COLOR_ERROR || blue == COLOR_ERROR)
		return (COLOR_ERROR);
	color = red << 16;
	color |= green << 8;
	color |= blue;
	return (color);
}
