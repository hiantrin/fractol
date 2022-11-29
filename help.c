/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:13:42 by hiantrin          #+#    #+#             */
/*   Updated: 2020/02/18 21:34:36 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_data *data, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->j = 0;
		print_pixel(data);
		mlx_mouse_hook(data->win_ptr, mouse_hook2, data);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		data->j = 1;
		print_pixel_julia(250, 300, data);
		mlx_hook(data->win_ptr, 6, 0, mouse_hook, data);
		mlx_mouse_hook(data->win_ptr, mouse_hook4, data);
	}
	if (ft_strcmp(argv[1], "burningship") == 0)
	{
		data->j = 2;
		print_pixel_2(data);
		mlx_mouse_hook(data->win_ptr, mouse_hook3, data);
	}
	mlx_key_hook(data->win_ptr, key_select, data);
	mlx_loop(data->mlx_ptr);
}

int		key_select(int key, t_data *data)
{
	double x;

	x = 0;
	if (key == 53)
	{
		free(data);
		exit(0);
	}
	if (key == 49)
	{
		if (data->space == 1)
			data->space = 0;
		else if (data->space == 0)
			data->space = 1;
	}
	if (key == 124)
	{
		x = data->xmax + (fabs(data->xmax - data->xmin) / 8);
		data->xmin = data->xmin + (fabs(data->xmax - data->xmin) / 8);
		data->xmax = x;
		type(data);
	}
	help_key_select(data, key, x);
	return (0);
}

void	print_pixel_2(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			data = remplir_data2(data, x, y, 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void	type(t_data *data)
{
	if (data->j == 0)
		print_pixel(data);
	else if (data->j == 1 && data->space == 0)
		print_pixel_julia_mouve(data);
	else if (data->j == 2)
		print_pixel_2(data);
}

void	help_key_select(t_data *data, int key, double x)
{
	if (key == 123)
	{
		x = data->xmax - (fabs(data->xmax - data->xmin) / 8);
		data->xmin = data->xmin - (fabs(data->xmax - data->xmin) / 8);
		data->xmax = x;
		type(data);
	}
	if (key == 125)
	{
		x = data->ymax + (fabs(data->ymax - data->ymin) / 8);
		data->ymin = data->ymin + (fabs(data->ymax - data->ymin) / 8);
		data->ymax = x;
		type(data);
	}
	if (key == 126)
	{
		x = data->ymax - (fabs(data->ymax - data->ymin) / 8);
		data->ymin = data->ymin - (fabs(data->ymax - data->ymin) / 8);
		data->ymax = x;
		type(data);
	}
}
