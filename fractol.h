/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:44:35 by hiantrin          #+#    #+#             */
/*   Updated: 2020/02/19 01:01:43 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W 800
# define H 800

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "math.h"

typedef struct	s_data
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img_ptr;
	int		*all;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	int		itr;
	int		space;
	double	zoom;
	double	xmaxs;
	double	xmins;
	int		j;
	double	ca;
	double	cb;
}				t_data;

typedef	struct	s_norme
{
	int x;
	int y;
	int xa;
	int xb;
}				t_norme;

void			print_pixel_julia(double x, double y, t_data *data);
int				mouse_hook(int x, int y, t_data *data);
int				mouse_hook2(int mousecode, int x, int y, t_data *data);
void			ft_zoom(t_data *data, double yo);
void			print_pixel_2(t_data *data);
void			ft_zoom2(t_data *data, double xo);
int				mouse_hook3(int mousecode, int x, int y, t_data *data);
t_data			*init_data(void);
void			draw(t_data *data, char **argv);
void			print_pixel(t_data *data);
t_data			*remplir_data(t_data *data, int x, int y, double a);
t_data			*remplir_data2(t_data *data, int x, int y, double a);
int				key_select(int key, t_data *data);
t_data			*remplir_data3(t_data *data, t_norme norme, double a);
t_data			*remplir_data4(t_data *data, t_norme norme, double a);
int				mouse_hook4(int mousecode, int x, int y, t_data *data);
void			ft_zoom_julia(t_data *data, int xo);
void			print_pixel_julia_mouve(t_data *data);
void			type(t_data *data);
void			help_key_select(t_data *data, int key, double x);
void			help_zoom(t_data *data, int xo);

#endif
