/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:52:44 by opacaud           #+#    #+#             */
/*   Updated: 2021/08/04 13:10:31 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_ber(char **av)
{
	int	size;

	size = ft_strlen(av[1]);
	if ((size < 5) || (av[1][size - 1] != 'r') || (av[1][size - 2] != 'e') ||
	(av[1][size - 3] != 'b') || (av[1][size - 4] != '.'))
		ft_write_and_exit("The map must have a .ber extension.\n");
}

void	ft_write_and_exit(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit (0);
}

void	ft_check_first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			ft_write_and_exit("The map must be surrounded by '1'.\n");
		i++;
	}
}

void	ft_check_middle_lines(char *line)
{
	int	i;

	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		ft_write_and_exit("The map must be surrounded by '1'.\n");
	i = 1;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P')
			ft_write_and_exit("The map must only contain 0, 1, C, E and P.\n");
		i++;
	}
}

void	ft_check_lines(char *line, t_sprites *sprites, unsigned int size)
{
	if (ft_strlen(line) != size)
		ft_write_and_exit("The map must be a rectangle.\n");
	ft_check_middle_lines(line);
	ft_actualiser_sprites(line, sprites);
}
