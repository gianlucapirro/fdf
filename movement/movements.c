/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/26 12:22:32 by gpirro        #+#    #+#                 */
/*   Updated: 2022/03/28 15:39:03 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
 takes the x, y and z of the current point and multiplies
 it by the zoom value
 */
void	zoom(t_point *p, t_params *params)
{
	p->x *= params->zoom;
	p->y *= params->zoom;
	p->z *= (params->zoom / 10);
}

/*
 takes the z value of the current point and then multiplies
 it by the elevation value
 */
void	elevate(t_point	*p, t_params *params)
{
	p->z *= params->elevation;
}

/*
 Performs three matrix transformations on x, y and z
 so that the point will be rotated correctly. x, y and z
 each have their own angle that is turned into a radian.
 */
void	rotate(t_point *p, t_params *params)
{
	double	rx;
	double	ry;
	double	rz;
	double	tmp;

	rx = deg_to_rad(params->dx);
	ry = deg_to_rad(params->dy);
	rz = deg_to_rad(params->dz);
	tmp = p->y;
	p->y = p->y * cos(rx) + p->z * sin(rx);
	p->z = -tmp * sin(rx) + p->z * cos(rx);
	tmp = p->x;
	p->x = p->x * cos(ry) + p->z * sin(ry);
	p->z = -tmp * sin(ry) + p->z * cos(ry);
	tmp = p->x;
	p->x = p->x * cos(rz) - p->y * sin(rz);
	p->y = tmp * sin(rz) + p->y * cos(rz);
}

/*
 adds move_x or move_y to the current x or y value so  that you 
 can move left, right, up and down.
 */
void	move(t_point *p, t_params *params)
{
	p->x += params->move_x;
	p->y += params->move_y;
}
