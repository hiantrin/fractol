/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:01:36 by hiantrin          #+#    #+#             */
/*   Updated: 2020/02/19 00:53:18 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_pixel(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			data = remplir_data(data, x, y, 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

t_data	*remplir_data(t_data *data, int x, int y, double a)
{
	double	b;
	double	ca;
	double	cb;
	double	ptr;

	a = (double)(((x * ((data->xmax - data->xmin)) / W)) + data->xmin);
	b = (double)(((y * ((data->ymax - data->ymin)) / H)) + data->ymin);
	ca = a;
	cb = b;
	data->itr = 0;
	while ((a * a + b * b) <= 4 && data->itr < 100)
	{
		ptr = a * a - b * b + ca;
		b = 2 * a * b + cb;
		a = ptr;
		data->itr++;
	}
	if (data->itr == 100)
		data->all[y * W + x] = 0;
	else
		data->all[y * W + x] = data->itr * 50;
	return (data);
}

int		main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || (ft_strcmp(argv[1], "mandelbrot") != 0 &&
		ft_strcmp(argv[1], "julia") != 0 &&
		ft_strcmp(argv[1], "burningship") != 0))
	{
		ft_putendl("Usage: fractol 'mandelbrot', 'julia', 'burningship'");
		exit(0);
	}
	data = init_data();
	draw(data, argv);
	return (0);
}

t_data	*init_data(void)
{
	t_data	*data;
	int		bip;
	int		size_line;
	int		edian;

	data = (t_data *)malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, W, H, "FRACTOL");
	data->img_ptr = mlx_new_image(data->mlx_ptr, W, H);
	data->all = (int *)mlx_get_data_addr(data->img_ptr, &bip,
		&size_line, &edian);
	data->xmin = -2.00;
	data->xmax = 2.00;
	data->ymin = -2.00;
	data->ymax = 2.00;
	data->itr = 0;
	data->space = 1;
	data->zoom = 0.2;
	return (data);
}
