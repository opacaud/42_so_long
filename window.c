/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:52:44 by opacaud           #+#    #+#             */
/*   Updated: 2021/08/05 11:23:35 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_create_window(t_window *window, int width, int height, char *title)
{
	if (width > 2560 || height > 1440)
		ft_write_and_exit("Please choose a smaller map.\n");
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == 0)
		return (0);
	window->win_ptr = mlx_new_window(window->mlx_ptr, width, height, title);
	if (window->win_ptr == 0)
	{
		free (window->mlx_ptr);
		return (0);
	}
	return (0);
}

void	ft_moves(t_total *total)
{
	total->moves++;
	ft_putnbr(total->moves);
	if (total->moves == 1)
		write(1, " move\n", 6);
	else
		write(1, " moves\n", 7);
}

void	ft_free(t_total *total)
{
	free(total->image_water);
	free(total->image_wall);
	free(total->image_dolphin);
	free(total->image_dolphin_left);
	free(total->image_fish);
	free(total->image_exit);
}

void	ft_destroy(t_total *total)
{
	if (total->image_water)
		mlx_destroy_image(total->window->mlx_ptr, total->image_water->img);
	if (total->image_wall)
		mlx_destroy_image(total->window->mlx_ptr, total->image_wall->img);
	if (total->image_dolphin)
		mlx_destroy_image(total->window->mlx_ptr, total->image_dolphin->img);
	if (total->image_dolphin_left)
		mlx_destroy_image(total->window->mlx_ptr, \
total->image_dolphin_left->img);
	if (total->image_fish)
		mlx_destroy_image(total->window->mlx_ptr, total->image_fish->img);
	if (total->image_exit)
		mlx_destroy_image(total->window->mlx_ptr, total->image_exit->img);
}

int	ft_close_window(t_total *total)
{
	int	i;

	i = 0;
	while (total->tab[i])
	{
		free(total->tab[i]);
		i++;
	}
	free(total->tab[i]);
	free(total->tab);
	ft_destroy(total);
	ft_free(total);
	mlx_clear_window(total->window->mlx_ptr, total->window->win_ptr);
	mlx_destroy_window(total->window->mlx_ptr, total->window->win_ptr);
	free(total->window->mlx_ptr);
	exit (0);
}
