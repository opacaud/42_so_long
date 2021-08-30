/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:52:44 by opacaud           #+#    #+#             */
/*   Updated: 2021/08/05 10:50:00 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_img_cp(t_total *total)
{
	t_image	image_fish;
	t_image	image_dolphin;
	t_image	image_dolphin_left;

	total->image_fish = malloc(sizeof(image_fish));
	if (total->image_fish == 0)
		return (0);
	total->image_dolphin = malloc(sizeof(image_dolphin));
	if (total->image_dolphin == 0)
		return (0);
	total->image_dolphin_left = malloc(sizeof(image_dolphin_left));
	if (total->image_dolphin_left == 0)
		return (0);
	total->image_fish->img = mlx_xpm_file_to_image(total->window->mlx_ptr, \
"textures/fish.xpm", &total->image_fish->width, &total->image_fish->height);
	total->image_dolphin->img = mlx_xpm_file_to_image(total->window->mlx_ptr, \
"textures/dolphin.xpm", &total->image_dolphin->width, \
&total->image_dolphin->height);
	total->image_dolphin_left->img = mlx_xpm_file_to_image(total->window->\
mlx_ptr, "textures/dolphin_left.xpm", &total->image_dolphin_left->width, \
&total->image_dolphin_left->height);
	return (0);
}

int	ft_get_img(t_total *total, t_window *window, t_position *position)
{
	t_image	image_water;
	t_image	image_wall;
	t_image	image_exit;

	total->window = window;
	total->position = position;
	total->image_water = malloc(sizeof(image_water));
	if (total->image_water == 0)
		return (0);
	total->image_wall = malloc(sizeof(image_wall));
	if (total->image_wall == 0)
		return (0);
	total->image_exit = malloc(sizeof(image_exit));
	if (total->image_exit == 0)
		return (0);
	total->image_water->img = mlx_xpm_file_to_image(total->window->mlx_ptr, \
"textures/water.xpm", &total->image_water->width, &total->image_water->height);
	total->image_wall->img = mlx_xpm_file_to_image(total->window->mlx_ptr, \
"textures/wall.xpm", &total->image_wall->width, &total->image_wall->height);
	total->image_exit->img = mlx_xpm_file_to_image(total->window->mlx_ptr, \
"textures/exit.xpm", &total->image_exit->width, &total->image_exit->height);
	ft_get_img_cp(total);
	return (0);
}
