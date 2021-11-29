#include "main.h"

void	draw_square(void *mlx, void *window, unsigned int start_x, unsigned int start_y, int color, int size_x)
{
	unsigned int	max_y;
	unsigned int	max_x;

	max_y = start_y;
	max_x = start_x + (unsigned int)size_x;
	while (start_x <= max_x)
	{
		start_y = 0;
		while (start_y <= max_y)
		{
			put_pixel(mlx, window, start_x, start_y, color);
			start_y++;
		}
		start_x++;
	}
}

void	draw_line(void *mlx, void *window, char **line, int size_x, int size_y)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	(void)size_y;
	i = 0;
	x = 0;
	y = 40;
	while (line[i])
	{
		draw_square(mlx, window, x, y, get_color(line[i]), size_x);
		i++;
		x = x + size_x;
	}
}