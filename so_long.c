/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:52:44 by opacaud           #+#    #+#             */
/*   Updated: 2021/08/05 13:41:05 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_detect(t_total *total)
{
	int	y;
	int	x;

	y = total->position->y / 40;
	x = total->position->x / 40;
	if (total->tab[y][x] == 'C')
	{
		total->sprites->c_gathered++;
		total->tab[y][x] = '0';
	}
	if (total->tab[y][x] == 'E'
			&& total->sprites->c_gathered == total->sprites->c)
	{
		write(1, "Thanks for all the fish!\n", 25);
		ft_close_window(total);
	}
}

int	main(int ac, char **av)
{
	t_window	window;
	t_sprites	sprites;
	t_position	position;
	t_total		total;

	if (ac != 2)
		ft_write_and_exit("Usage: so_long map.ber\n");
	total.sprites = &sprites;
	ft_check_map(av, &sprites, &window);
	ft_create_window(&window, window.width * 40, window.height * 40, "so_long");
	ft_get_img(&total, &window, &position);
	ft_print_textures(&total, av);
	mlx_hook(window.win_ptr, 2, 1L << 0, ft_key_press, &total);
	mlx_hook(window.win_ptr, 17, 0, ft_close_window, &total);
	mlx_loop(window.mlx_ptr);
}
