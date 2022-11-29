/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:55:25 by hiantrin          #+#    #+#             */
/*   Updated: 2020/02/18 21:48:02 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(t_data *data, double xo)
{
	int		x;
	int		y;

	y = 0;
	help_zoom(data, xo);
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			remplir_data(data, x, y, 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void	ft_zoom2(t_data *data, double xo)
{
	int		x;
	int		y;

	y = 0;
	help_zoom(data, xo);
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			remplir_data2(data, x, y, 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

t_data	*remplir_data2(t_data *data, int x, int y, double a)
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
		a = fabs(a);
		b = fabs(b);
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

void	ft_zoom_julia(t_data *data, int xo)
{
	int		x;
	int		y;
	t_norme	norme;

	help_zoom(data, xo);
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			norme.x = x;
			norme.y = y;
			data = remplir_data4(data, norme, 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void	help_zoom(t_data *data, int xo)
{
	if (xo == 1)
	{
		data->xmax = data->xmax - (fabs(data->xmax - data->xmin) / 4);
		data->ymax = data->ymax - (fabs(data->ymax - data->ymin) / 4);
		data->xmin = data->xmin + (fabs(data->xmax - data->xmin) / 4);
		data->ymin = data->ymin + (fabs(data->ymax - data->ymin) / 4);
	}
	if (xo == 2)
	{
		data->xmax = data->xmax + (fabs(data->xmax - data->xmin) / 4);
		data->ymax = data->ymax + (fabs(data->ymax - data->ymin) / 4);
		data->xmin = data->xmin - (fabs(data->xmax - data->xmin) / 4);
		data->ymin = data->ymin - (fabs(data->ymax - data->ymin) / 4);
	}
}
