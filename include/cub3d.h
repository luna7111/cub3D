/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   cub3d.h                                       *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: cde-migu <marvin@42.fr>                    (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/18 15:46:25 by cde-migu                      *    .     */
/*   Updated: 2025/07/18 18:32:22 by cde-migu       tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../gctrl/src/garbage_control.h"

# define PROG_BLOCK 1
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

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		floor_color;
	int		ceiling_color;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
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

#endif
