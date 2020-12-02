#include "lib/mlx_linux/mlx.h"
#include <stdio.h>

typedef struct	s_data {
void	*img;
char	*addr;
int		bits_per_pixel;
int		line_length;
int		endian;
}				t_data;

typedef struct	s_vars {
void	*mlx;
void	*win;
}				t_vars;


void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char		*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void			ft_print_square(t_vars *vars, int side, t_data *img, int color, int width, int height)
{
	int		i;
	int		j;

	img->img = mlx_new_image(vars->mlx, side, side);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
		&img->endian);
	i = 0;
	while (i < side)
	{
		j = 0;
		while (j < side)
		{
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, (width - i) / 2, (height - j) / 2);
}

int		ft_print_key(int keycode, t_vars *vars)
{
	printf("Key %d pressed\n", keycode);
	return (0);
}

int			main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 800, "Hello world!");
	ft_print_square(&vars, 500, &img, 0x00FF0000, 1000, 800);
	mlx_key_hook(vars.win, ft_print_key, &vars);
	mlx_loop(vars.mlx);
}