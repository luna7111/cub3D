#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "../gctrl/src/garbage_control.h"

#include <math.h>

#define PROG_BLOCK 1

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_NAME "CUB3D"
#define TEST_WINDOW_NAME "REFERENCE RENDER"
#define FOV 60

typedef struct s_player
{
	float	x;
	float	y;
	float	dir;
}	t_player;

#define	I_LEFT 0b00000001
#define	I_RIGHT 0b00000010
#define	I_W 0b00000100
#define	I_A 0b00001000
#define	I_S 0b00010000
#define	I_D 0b00100000

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

typedef struct s_data
{
	char		**map;
	int			map_height;
	int			map_width;
	t_player	*player;
	t_gctrl		gctrl;
	void		*mlx;
	void		*window;
	void		*image;
	void		*image_address;
	int			img_bpp;
	int			img_l_len;
	int			img_endian;
	int			input;
	void		*north_texture;	
	void		*north_addr;	
	void		*south_texture;	
	void		*south_addr;	
	void		*east_texture;	
	void		*east_addr;	
	void		*west_texture;	
	void		*west_addr;	
/////////////////
	void		*window_test;
	void		*image_test;
	void		*image_address_test;
	int			img_bpp_test;
	int			img_l_len_test;
	int			img_endian_test;
/////////////////
}	t_data;
