/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   cub3d.h                                       *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: cde-migu <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/18 15:46:25 by cde-migu                      *    .     */
/*   Updated: 2025/08/07 14:23:48 by luna           tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../gctrl/src/garbage_control.h"
# include <stdbool.h>

# define PROG_BLOCK 1
# define MISSING_TEXTURE_XPM 2

# define FOV 60
# define TITLE "cub3d" //revisar
# define WIN_HEIGHT 600
# define WIN_WIDTH 800

typedef struct s_player
{
	float	x;
	float	y;
	float	dir;
	int		input;
}	t_player;

# define COLOR_UNSET -1
# define COLOR_ERROR -2

# define DEFAULT_COLOR 0x639363

# define TILE_EMPTY '0'
# define TILE_FLOOR '1'
# define TILE_WALL '2'

typedef struct s_map
{
	char	**grid;
	size_t	height;
	size_t	width;
	int		floor_color;
	int		ceiling_color;
    int     error;
}	t_map;

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	bool	is_set;
	bool	error;
}	t_img;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_gctrl		*gctrl;
	void		*mlx;
	void		*win;
	t_img		base_img;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
}	t_game;

# define INITIAL_CAPACITY 64

typedef struct s_file_content
{
	char	**content;
	size_t	line_number;
	size_t	capacity;
	int		error;
}	t_file_content;

int				check_attribute_repetition(char **file_content);

t_file_content	load_file(t_gctrl *gctrl, char *filename);

int				parse_rgb(char *rgb);

char			*get_attribute_value(const char *line);

void			scan_atributes(t_file_content file, t_game *game);
void			scan_map(t_file_content file, t_game *game);

int				check_map_borders(t_game *game);

void			parse_file(t_gctrl *gctrl, t_game *game, char *filename);

void			safe_exit(t_game *game);

t_game			*init_game(t_gctrl *gctrl, char *filename);

void            init_hooks(t_game *game);
#endif
