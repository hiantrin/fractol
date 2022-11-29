/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:18:31 by hiantrin          #+#    #+#             */
/*   Updated: 2020/02/18 21:37:14 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int x, int y, t_data *data)
{
	if (data->space == 1)
		print_pixel_julia(x, y, data);
	return (0);
}

int		mouse_hook2(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mousecode == 5)
		ft_zoom(data, 1);
	else if (mousecode == 4)
		ft_zoom(data, 2);
	return (0);
}

int		mouse_hook3(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mousecode == 5)
		ft_zoom2(data, 1);
	else if (mousecode == 4)
		ft_zoom2(data, 2);
	return (0);
}

int		mouse_hook4(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mousecode == 5 && data->space == 0)
		ft_zoom_julia(data, 1);
	else if (mousecode == 4 && data->space == 0)
		ft_zoom_julia(data, 2);
	return (0);
}
