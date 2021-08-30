/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:52:44 by opacaud           #+#    #+#             */
/*   Updated: 2021/08/04 09:45:23 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_w_key(t_total *total)
{
	int	y;
	int	x;

	y = total->position->y / 40;
	x = total->position->x / 40;
	if (total->tab[y - 1][x] != '1')
	{
		if (total->tab[y][x] != 'E')
			mlx_put_image_to_window(total->window->mlx_ptr, total->window->\
win_ptr, total->image_water->img, total->position->x, total->position->y);
		else
			mlx_put_image_to_window(total->window->mlx_ptr, total->window->\
win_ptr, total->image_exit->img, total->position->x, total->position->y);
		mlx_put_image_to_window(total->window->mlx_ptr, total->window->win_ptr, \
total->image_dolphin->img, total->position->x, total->position->y - 40);
		total->position->y -= 40;
		ft_moves(total);
	}
	ft_detect(total);
}

void	ft_a_key(t_total *total)
{
	int	y;
	int	x;

	y = total->position->y / 40;
	x = total->position->x / 40;
	if (total->tab[y][x - 1] != '1')
	{
		if (total->tab[y][x] != 'E')
			mlx_put_image_to_window(total->window->mlx_ptr, total->window->\
win_ptr, total->image_water->img, total->position->x, total->position->y);
		else
			mlx_put_image_to_window(total->window->mlx_ptr, total->window->\
win_ptr, total->image_exit->img, total->position->x, total->position->y);
		mlx_put_image_to_window(total->window->mlx_ptr, total->window->win_ptr, \
total->image_dolphin_left->img, total->position->x - 40, total->position->y);
		total->position->x -= 40;
		ft_moves(total);
	}
	ft_detect(total);
}

void	ft_s_key(t_total *total)
{
	int	y;
	int	x;

	y = total->position->y / 40;
	x = total->position->x / 40;
	if (total->tab[y + 1][x] != '1')
	{
		if (total->tab[y][x] != 'E')
			mlx_put_image_to_window(total->window->mlx_ptr, total->window->\
win_ptr, total->image_water->img, total->position->x, total->position->y);
		else
			mlx_put_image_to_window(total->window->mlx_ptr, total->window->\
win_ptr, total->image_exit->img, total->position->x, total->position->y);
		mlx_put_image_to_window(total->window->mlx_ptr, total->window->win_ptr, \
total->image_dolphin->img, total->position->x, total->position->y + 40);
		total->position->y += 40;
		ft_moves(total);
	}
	ft_detect(total);
}

void	ft_d_key(t_total *total)
{
	int	y;
	int	x;

	y = total->position->y / 40;
	x = total->position->x / 40;
	if (total->tab[y][x + 1] != '1')
	{
		if (total->tab[y][x] != 'E')
			mlx_put_image_to_window(total->window->mlx_ptr, total->window->\
win_ptr, total->image_water->img, total->position->x, total->position->y);
		else
			mlx_put_image_to_window(total->window->mlx_ptr, total->window->\
win_ptr, total->image_exit->img, total->position->x, total->position->y);
		mlx_put_image_to_window(total->window->mlx_ptr, total->window->win_ptr, \
total->image_dolphin->img, total->position->x + 40, total->position->y);
		total->position->x += 40;
		ft_moves(total);
	}
	ft_detect(total);
}

int	ft_key_press(int key, t_total *total)
{
	if (key == 53)
		ft_close_window(total);
	else if (key == 13 || key == 126)
		ft_w_key(total);
	else if (key == 0 || key == 123)
		ft_a_key(total);
	else if (key == 1 || key == 125)
		ft_s_key(total);
	else if (key == 2 || key == 124)
		ft_d_key(total);
	return (0);
}
