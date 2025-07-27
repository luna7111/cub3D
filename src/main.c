/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: cde-migu <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/18 15:30:23 by cde-migu                      *    .     */
/*   Updated: 2025/07/27 20:37:39 by luna           tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	game->base_img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->base_img.addr = mlx_get_data_addr(game->base_img.img,
			&game->base_img.bpp, &game->base_img.l_len, &game->base_img.endian);
}
/* yo haría una función para inicializar una textura y pondría cuatro */
/* llamadas a esa función dentro de esta :) */

# define INITIAL_CAPACITY 64
typedef struct s_file_content
{
	char	**content;
	size_t	line_number;
	size_t	capacity;
	int		error;
}	t_file_content;

void	duplicate_capacity(t_gctrl *gctrl, t_file_content *file)
{
	char	**resized_content;
	size_t	i;

	resized_content = gctrl_malloc(gctrl, PROG_BLOCK,
			sizeof(char *) * file->capacity * 2);
	i = 0;
	while (i < file->capacity)
	{
		resized_content[i] = file->content[i];
		i++;
	}
	gctrl_free(gctrl, file->content);
	file->content = resized_content;
}

t_file_content	load_file(t_gctrl *gctrl, char *filename)
{
	t_file_content file;
	int				fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (file.error = 1, file);
	file.capacity = INITIAL_CAPACITY;
	file.content = gctrl_malloc(gctrl, PROG_BLOCK, sizeof(char *) * file.capacity);
	file.line_number = 0;	
	file.content[file.line_number] = get_next_line(fd);
	while (file.content[file.line_number])
	{
		file.line_number ++;
		if (file.line_number >= file.capacity)
			duplicate_capacity(gctrl, &file);
		file.content[file.line_number] = get_next_line(fd);
	}
	close(fd);
	return (file.error = 0, file);
}

char	**get_missing_texture(t_game *game)
{
	char **xpm;

	xpm = gctrl_malloc(game->gctrl, PROG_BLOCK, sizeof(char *) * 5);
	xpm[0] = ft_strdup("2 2 2 1");
	xpm[1] = ft_strdup(". c #000000");
	xpm[2] = ft_strdup("# c #f800f8");
	xpm[3] = ft_strdup(".#");
	xpm[4] = ft_strdup("#.");
//	xpm[5] = NULL;
	return (xpm);
}

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

t_img	get_texture_from_attribute(t_game *game, char *attribute_line)
{
	t_img	texture;
	char	*filename;

	texture.is_set = 1;
	filename = get_attribute_value(attribute_line);
	texture.img = mlx_xpm_file_to_image(game->mlx, filename, &texture.width,
			&texture.height);
	if (texture.img == NULL)
		return (texture.error = 1, texture);
	texture.addr = mlx_get_data_addr(texture.img, &texture.bpp,
		&texture.l_len, &texture.endian);
	free(filename);
	return (texture.error = 0, texture);
}

int		parse_comma_separated_number(char *str)
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

int		parse_rgb(char *rgb)
{
	int red;
	int green;
	int blue;
	int color;

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

int		get_color_from_attribute(t_game *game, char *attribute_line)
{
	int		color;
	char	*value; 

	value = get_attribute_value(attribute_line);
	color = parse_rgb(value);
	free(value);
	(void)game;
	return (color);
}

void	init_attributes_to_zero(t_game *game)
{
	game->north.is_set = 0;
	game->south.is_set = 0;
	game->east.is_set = 0;
	game->west.is_set = 0;
	game->map.floor_color = COLOR_UNSET;
	game->map.ceiling_color = COLOR_UNSET;
}

void	scan_atributes(t_file_content file, t_game *game)
{
	size_t	i;

	init_attributes_to_zero(game);
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

int		is_line_valid_map_section(const char *line)
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
}

void	parse_file(t_gctrl *gctrl, t_game *game, char *filename)
{
	t_file_content	file;

	file = load_file(gctrl, filename);
	scan_atributes(file, game);	
	scan_map(file, game);
}

t_game	*init_game(t_gctrl *gctrl, char *filename)
{
	t_game	*game;

	game = gctrl_malloc(gctrl, PROG_BLOCK, sizeof(t_game));
	game->gctrl = gctrl;
	init_graphics(game);
	parse_file(gctrl, game, filename);
	return (game);
}
/* habrá que actualizarla con las cosas del parseo bien :) */

void	debug_texture_dump(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->north.img, 0,0);
	mlx_put_image_to_window(game->mlx, game->win, game->south.img, 128,0);
	mlx_put_image_to_window(game->mlx, game->win, game->east.img, 256,0);
	mlx_put_image_to_window(game->mlx, game->win, game->west.img, 384,0);
	int x = 0;
	int y = 0;
	while (y < 258) {
		
		while (x < 258) {
	
			if (game->map.grid[(x * game->map.width) / 258][(y * game->map.height) / 258] == '1')
				mlx_pixel_put(game->mlx, game->win, 128 + x, 128 + y, 0xFFFFFF);
			x++;
		}
		y++;
		x = 0;
	}
	x = 0;
	y = 0;
	while (y < 64) {
		while (x < 64) {
			mlx_pixel_put(game->mlx, game->win, x, 128 + y, game->map.ceiling_color);
			mlx_pixel_put(game->mlx, game->win, x, 192 + y, game->map.floor_color);
			x++;
		}
		x = 0;
		y++;
	}
}

int main(int argn, char **argv)
{
	t_gctrl	*gctrl;
	t_game	*game;

	if (argn != 2)
		return (0);
	gctrl = gctrl_init();
	game = init_game(gctrl, argv[1]);
	debug_texture_dump(game);
	mlx_loop(game->mlx);
	gctrl_terminate(gctrl);
}
/*                     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ */
/*                   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ */
/*                   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ */
/*                   ▒▒██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒ */
/*                   ▒▒▒▒▒▒  ░░  ▒▒▒▒▒▒▒▒ */
/*                   ▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒ */
/*                   ▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒ */
/*                     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ */
/*                   ▓▓▒▒▓▓▒▒▒▒▒▒▒▒▓▓░░ */
/*                 ▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓░░ */
/*                 ▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░░░ */
/*                 ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░░░░░ */
/*               ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░▒▒░░░░ */
/*             ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░▒▒▒▒▒▒▒▒ */
/*             ▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒░░░░▒▒▒▒▒▒▒▒ */
/*             ▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▓▓▓▓▒▒ */
/*               ▒▒░░░░░░░░░░░░░░░░░░░░░░░░▓▓▒▒▒▒▓▓ */
/*                 ░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓▒▒ */
/*                 ░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░ */
/*                   ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ */
/*                       ░░░░░░░░░░░░░░░░░░░░░░░░ */
/* ▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓░░▓▓▒▒▓▓▒▒▓▓░░▓▓▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓▓▓▒▒▓▓▒▒ */
/*                       ░░          ░░░░▒▒░░▒▒░░ */
/*                                     ░░▒▒░░▒▒░░ */
/*                                     ░░▒▒░░▒▒░░ */
/*                                     ░░▒▒░░▒▒░░ */
/*                                       ▒▒░░▒▒ */
