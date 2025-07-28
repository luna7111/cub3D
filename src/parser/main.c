/* ************************************************************************** */
/*                                                                            */
/*                                                     +      *     .         */
/*   main.c                                        *  ___  .  ___       .     */
/*                                                   (o o)   (o o)  +         */
/*   By: luna <marvin@42.fr>                        (  V  ) (  V  )  .        */
/*                                                 /--m-m- /--m-m-    +       */
/*   Created: 2025/07/28 17:12:00 by luna                          *    .     */
/*   Updated: 2025/07/28 20:23:46 by luna           tortolitas       .        */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	parse_file(t_gctrl *gctrl, t_game *game, char *filename)
{
	t_file_content	file;

	file = load_file(gctrl, filename);
	if (!check_attribute_repetition(file.content))
	{
		printf("Error: redefinition of the same attribute.\n");
		exit (0);
		/* something something safe exit something something :p */
	}
	scan_atributes(file, game);
	scan_map(file, game);
}
