/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:12:36 by hiantrin          #+#    #+#             */
/*   Updated: 2020/02/18 21:51:06 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_pixel_julia(double xa, double xb, t_data *data)
{
	int		x;
	int		y;
	t_norme	norme;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			norme.x = x;
			norme.y = y;
			norme.xa = xa;
			norme.xb = xb;
			data = remplir_data3(data, norme, 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

t_data	*remplir_data3(t_data *data, t_norme norme, double a)
{
	double	b;
	double	ca;
	double	cb;
	double	ptr;

	a = (double)(((norme.x * ((data->xmax - data->xmin)) / W)) + data->xmin);
	b = (double)(((norme.y * ((data->ymax - data->ymin)) / H)) + data->ymin);
	ca = (double)(((norme.xa) * (data->xmax - data->xmin)) / W) + data->xmin;
	cb = (double)(((norme.xb) * (data->ymax - data->ymin)) / H) + data->ymin;
	data->ca = ca;
	data->cb = cb;
	data->itr = 0;
	while ((a * a + b * b) <= 4 && data->itr < 100)
	{
		ptr = a * a - b * b + ca;
		b = 2 * a * b + cb;
		a = ptr;
		data->itr++;
	}
	if (data->itr == 100)
		data->all[norme.y * W + norme.x] = 0;
	else
		data->all[norme.y * W + norme.x] = data->itr * 50;
	return (data);
}

t_data	*remplir_data4(t_data *data, t_norme norme, double a)
{
	double	b;
	double	ca;
	double	cb;
	double	ptr;

	a = (double)(((norme.x * ((data->xmax - data->xmin)) / W)) + data->xmin);
	b = (double)(((norme.y * ((data->ymax - data->ymin)) / H)) + data->ymin);
	ca = data->ca;
	cb = data->cb;
	data->itr = 0;
	while ((a * a + b * b) <= 4 && data->itr < 100)
	{
		ptr = a * a - b * b + ca;
		b = 2 * a * b + cb;
		a = ptr;
		data->itr++;
	}
	if (data->itr == 100)
		data->all[norme.y * W + norme.x] = 0;
	else
		data->all[norme.y * W + norme.x] = data->itr * 50;
	return (data);
}

void	print_pixel_julia_mouve(t_data *data)
{
	int		x;
	int		y;
	t_norme	norme;

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
