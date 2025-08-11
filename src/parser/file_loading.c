/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   file_loading.c                                *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/28 15:19:49 by luna                          *    .     */
/*   Updated: 2025/08/11 21:54:02 by luna           tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	file->capacity *= 2;
}
/* mirar si hacer falta cambiar el tamaño de file capacity */

bool	check_file_name(const char *filename)
{
	char *file_extension;

	file_extension = ft_strrchr(filename, '.');
	if (file_extension == NULL)
		return (false);
	if (ft_strncmp(file_extension, ".cub", 5))
		return (false);
	return(true);
}

t_file_content	load_file(t_gctrl *gctrl, char *filename)
{
	t_file_content	file;
	int				fd;

	if (!check_file_name(filename))
		return (file.error = 1, file);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (file.error = 1, file);
	file.capacity = INITIAL_CAPACITY;
	file.content = gctrl_malloc(gctrl, PROG_BLOCK,
			sizeof(char *) * file.capacity);
	file.line_number = 0;
	file.content[file.line_number] = get_next_line(fd);
	while (file.content[file.line_number] != NULL)
	{
		gctrl_track_ptr(gctrl, file.content[file.line_number], PROG_BLOCK);
		file.line_number ++;
		if (file.line_number >= file.capacity)
			duplicate_capacity(gctrl, &file);
		file.content[file.line_number] = get_next_line(fd);
	}
	close(fd);
	return (file.error = 0, file);
}

/* comprobar si el resize funciona bien!!! */
