/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:52:44 by opacaud           #+#    #+#             */
/*   Updated: 2021/08/04 13:10:35 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialiser_sprites(t_sprites *sprites)
{
	sprites->one = 0;
	sprites->zero = 0;
	sprites->c = 0;
	sprites->e = 0;
	sprites->p = 0;
	sprites->c_gathered = 0;
}

void	ft_actualiser_sprites(char *line, t_sprites *sprites)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			(sprites->one)++;
		else if (line[i] == '0')
			(sprites->zero)++;
		else if (line[i] == 'C')
			(sprites->c)++;
		else if (line[i] == 'E')
			(sprites->e)++;
		else if (line[i] == 'P')
			(sprites->p)++;
		i++;
	}
}

void	ft_check_sprites(t_sprites *sprites)
{
	if (sprites->one == 0 || sprites->zero == 0 || sprites->c == 0
		|| sprites->e == 0 || sprites->p == 0)
		ft_write_and_exit("The map must at least contain one E, C and P.\n");
	if (sprites->p > 1)
		ft_write_and_exit("The map must have only one P.\n");
}

int	ft_open(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit (0);
	return (fd);
}

void	ft_check_map(char **av, t_sprites *sprites, t_window *window)
{
	int		fd;
	char	*line;
	int		ret;

	ft_initialiser_sprites(sprites);
	ft_check_ber(av);
	fd = ft_open(av);
	window->height = 0;
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ret != 0)
			window->height++;
		if (window->height == 1)
			window->width = ft_strlen(line);
		if (window->height == 1 || ret == 0)
			ft_check_first_last_line(line);
		else
			ft_check_lines(line, sprites, window->width);
	}
	close(fd);
	ft_check_sprites(sprites);
}
