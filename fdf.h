/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:40:07 by gpirro        #+#    #+#                 */
/*   Updated: 2022/04/19 14:01:52 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "gnl/gnl.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "list/list.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <math.h>
# include <time.h>

typedef struct s_map {
	int	**field;
	int	w;
	int	h;
}		t_map;

typedef struct s_params {
	void	*mlx;
	char	*mlx_win;
	double	deg;
	double	zoom;
	double	move_y;
	double	move_x;
	double	dx;
	double	dy;
	double	dz;
	double	elevation;
	t_map	*map;
}		t_params;

typedef struct s_point {
	double	x;
	double	y;
	double	z;
}		t_point;

typedef struct s_line {
	t_point	p1;
	t_point	p2;
}		t_line;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_iter {
	int	i;
	int	j;
}		t_iter;

typedef enum e_keys
{
	ARROW_R	= 124,
	ARROW_L	= 123,
	ARROW_U	= 125,
	ARROW_D	= 126,
	PAGE_U	= 116,
	PAGE_D	= 121,
	PLUS	= 24,
	ESC		= 53,
	MIN		= 27,
	Q		= 12,
	W		= 13,
	E		= 14,
	A		= 0,
	S		= 1,
	D		= 2
}	t_keys;

# define WINDOW_WIDTH 2560
# define WINDOW_HEIGHT 1600
# define PI 3.14159

t_map	*handle_input(int fd);
double	deg_to_rad(double deg);
void	draw_map(t_params *params, t_data *img);
void	put_pixel(t_data *data, int x, int y, int color);
void	draw_line(t_data *data, t_point *p1, t_point *p2);
void	zoom(t_point *p, t_params *params);
void	elevate(t_point	*p, t_params *params);
void	rotate(t_point *p, t_params *params);
void	move(t_point *p, t_params *params);
void	key_press2(int keycode, t_params *params);
int		key_press(int keycode, t_params *params);
int		close_win(t_params	*params);

#endif