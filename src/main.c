/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: cde-migu <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/18 15:30:23 by cde-migu                      *    .     */
/*   Updated: 2025/07/23 21:29:01 by ldel-val       tortolitas       .        */
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
	int		line_number;
	int		capacity;
}	t_file_content;

void	duplicate_capacity(t_gctrl *gctrl, t_file_content *file)
{
	char	**resized_content;
	size_t	i;

	resized_content = gctrl_malloc(gctrl, PROG_BLOCK,
			sizeof(char *) * file->size * 2);
	i = 0;
	while (i < file->capacity)
	{
		resized_content[i] = file->content[i];
		i++;
	}
	gctrl_free(file->content);
	file->content = resized_content;
}

t_file_content	load_file(t_gctrl *gctrl, char *filename)
{
	t_file_content file;
	int				fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file.capacity = INITIAL_CAPACITY;
	file.content = gctrl_malloc(gctrl, PROG_BLOCK, sizeof(char *) * size);
	file.line_number = 0;	
	file.content[file.line_number] = get_next_line(fd);
	while (file.content[file.line_number])
	{
		file.line_number ++;
		if (file.line_number => file.capaciy)
			duplicate_capacity(gctrl, &file);
		file.content[file.line_number] = get_next_line(fd);
	}
	close(fd);
	return (file);
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

	filename = get_attribute_value(attribute_line);
	texture->img = mlx_xpm_file_to_image(game->mlx, filename, &texture->width,
			&texture->height);	
	/* maybe add some kind of check for the file opening? */
	free(filename);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
		&texture->l_len, &texture->endian);
	return (texture);
}

void	scan_atributes(t_file_content file, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < file.line_number)
	{
		if (ft_strncmp(file.content[i], "NO ", 3))
			game->north = get_texture_from_attribute(game, file.content[i]);
		else if (ft_strncmp(file.content[i], "SO ", 3))
			//...
		else if (ft_strncmp(file.content[i], "WE ", 3))
			//...
		else if (ft_strncmp(file.content[i], "EA ", 3))
			//...
		else if (ft_strncmp(file.content[i], "F ", 2))
			//...
		else if (ft_strncmp(file.content[i], "C ", 2))
	}
}

void	parse_file(t_gctrl *gctrl, t_game *game, char *filename)
{
	t_file_content	file;

	file = load_file(gctrl, filename);
	scan_atributes(file, game);	
}

t_game	*init_game(t_gctrl *gctrl, char *filename)
{
	t_game	*game;

	game = gctrl_malloc(gctrl, PROG_BLOCK, sizeof(t_game));
	parse_file(gctrl, game, filename);
	init_graphics(game);
	return (game);
}
/* habrá que actualizarla con las cosas del parseo bien :) */

int main(int argn, char **argv)
{
	t_gctrl	*gctrl;
	t_game	*game;

	gctrl = gctrl_init();
	game = init_game(gctrl, argv[1]);
	while (1)
		;
	(void)game;
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
