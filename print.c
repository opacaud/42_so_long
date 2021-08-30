/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:52:44 by opacaud           #+#    #+#             */
/*   Updated: 2021/08/04 10:57:07 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_line_cep(t_total *total, char *line, int i, int count)
{
	if (line[i] == 'C')
		mlx_put_image_to_window(total->window->mlx_ptr, \
total->window->win_ptr, total->image_fish->img, i * 40, count * 40);
	else if (line[i] == 'E')
		mlx_put_image_to_window(total->window->mlx_ptr, \
total->window->win_ptr, total->image_exit->img, i * 40, count * 40);
	else if (line[i] == 'P')
	{
		mlx_put_image_to_window(total->window->mlx_ptr, \
total->window->win_ptr, total->image_dolphin->img, i * 40, count * 40);
		total->position->x = i * 40;
		total->position->y = count * 40;
	}
}

void	ft_print_line(t_total *total, char *line, int count)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			mlx_put_image_to_window(total->window->mlx_ptr, \
total->window->win_ptr, total->image_water->img, i * 40, count * 40);
		else if (line[i] == '1')
			mlx_put_image_to_window(total->window->mlx_ptr, \
total->window->win_ptr, total->image_wall->img, i * 40, count * 40);
		else
			ft_print_line_cep(total, line, i, count);
		i++;
	}
}

int	ft_fill_it_up(char *line, char **tab, int count)
{
	int	i;

	i = 0;
	tab[count] = (char *)malloc(ft_strlen(line) + 1);
	if (tab[count] == 0)
		return (0);
	while (line[i])
	{
		tab[count][i] = line[i];
		i++;
	}
	tab[count][i] = '\0';
	return (0);
}

int	ft_print_textures(t_total *total, char **av)
{
	char		*line;
	int			fd;
	int			ret;
	int			count;

	total->moves = 0;
	fd = ft_open(av);
	ret = 1;
	count = 0;
	total->tab = (char **)malloc(sizeof(char *) * (total->window->height + 1));
	if (total->tab == 0)
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == 0)
			break ;
		ft_fill_it_up(line, total->tab, count);
		ft_print_line(total, line, count);
		count++;
	}
	total->tab[count] = 0;
	close (fd);
	return (0);
}
