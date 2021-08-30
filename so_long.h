/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:54:29 by opacaud           #+#    #+#             */
/*   Updated: 2021/08/05 11:28:45 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"

# include <stdio.h>

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}				t_window;

typedef struct s_sprites
{
	int	one;
	int	zero;
	int	c;
	int	e;
	int	p;
	int	c_gathered;
}				t_sprites;

typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
}				t_image;

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_total
{
	t_window	*window;
	t_sprites	*sprites;
	t_image		*image_water;
	t_image		*image_wall;
	t_image		*image_fish;
	t_image		*image_dolphin;
	t_image		*image_dolphin_left;
	t_image		*image_exit;
	t_position	*position;
	char		**tab;
	int			moves;
}				t_total;

void			ft_check_ber(char **av);
void			ft_write_and_exit(char *message);
void			ft_check_first_last_line(char *line);
void			ft_check_middle_lines(char *line);
void			ft_check_lines(char *line, t_sprites *sprites, \
				unsigned int size);

void			ft_initialiser_sprites(t_sprites *sprites);
void			ft_actualiser_sprites(char *line, t_sprites *sprites);
void			ft_check_sprites(t_sprites *sprites);
int				ft_open(char **av);
void			ft_check_map(char **av, t_sprites *sprites, \
				t_window *window);

char			*ft_before(char *str);
char			*ft_after(char *str);
int				get_next_line(int fd, char **line);

unsigned int	ft_strlen(char *s);
int				ft_hasnewline(char *s);
char			*ft_strjoin(char *s1, char *s2);

void			ft_w_key(t_total *total);
void			ft_a_key(t_total *total);
void			ft_s_key(t_total *total);
void			ft_d_key(t_total *total);
int				ft_key_press(int key, t_total *total);

void			ft_print_line_cep(t_total *total, char *line, int i, int count);
void			ft_print_line(t_total *total, char *line, int count);
int				ft_fill_it_up(char *line, char **tab, int count);
int				ft_print_textures(t_total *total, char **av);

void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_detect(t_total *total);

int				ft_get_img_cp(t_total *total);
int				ft_get_img(t_total *total, t_window *window, \
				t_position *position);

int				ft_create_window(t_window *window, int width, int height, \
				char *title);
void			ft_moves(t_total *total);
void			ft_free(t_total *total);
void			ft_destroy(t_total *total);
int				ft_close_window(t_total *total);

#endif
