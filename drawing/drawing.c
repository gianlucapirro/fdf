/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/24 15:09:45 by gpirro        #+#    #+#                 */
/*   Updated: 2022/04/21 10:54:10 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
 Takes a degree as a double and turns it into a radian
 */
double	deg_to_rad(double deg)
{
	return ((PI / 180) * deg);
}

/*
 Takes t_point p which is a 3d point that has a (x, y, z).
 It performs a matrix tranformation on the x and y with z. 
 (isometric transformation)
 */
static void	iso_project(t_point *p, t_params *params)
{
	int		new_x;
	int		new_y;
	double	rad;

	rad = deg_to_rad(params->deg);
	new_x = (p->x - p->y) * cos(rad);
	new_y = -(p->z) + (p->x + p->y) * sin(rad);
	p->x = new_x;
	p->y = new_y;
}

/*
 Updates the points after the movements and the isometric transformation
 */
static void	project_point(int x, int y, t_params *params, t_point *p)
{
	p->x = (double)x;
	p->y = (double)y;
	p->z = (double)params->map->field[y][x];
	zoom(p, params);
	elevate(p, params);
	rotate(p, params);
	iso_project(p, params);
	move(p, params);
}

/*
 loops though length and width of map. Than it passes the
 x and y to eventually draw the map
 */
void	draw_map(t_params *params, t_data *img)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = -1;
	while (++y < params->map->h)
	{
		x = -1;
		while (++x < params->map->w)
		{
			project_point(x, y, params, &p1);
			if (x < params->map->w - 1)
			{
				project_point(x + 1, y, params, &p2);
				draw_line(img, &p1, &p2);
			}
			if (y < params->map->h - 1)
			{
				project_point(x, y + 1, params, &p2);
				draw_line(img, &p1, &p2);
			}
		}
	}
}
