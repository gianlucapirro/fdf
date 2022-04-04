/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/26 16:13:45 by gpirro        #+#    #+#                 */
/*   Updated: 2022/04/04 16:23:58 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
 This function is called in a hook, so it will wait until 
 a key is pressed. If the key that is pressed matches one 
 of the keycodes in the if statements an action will take place.
 */
void	key_press2(int keycode, t_params *params)
{
	if (keycode == PLUS)
		params->zoom += 5;
	if (keycode == MIN)
		params->zoom -= 5;
	if (keycode == Q)
		params->dx += 5;
	if (keycode == W)
		params->dy += 5;
	if (keycode == E)
		params->dz += 5;
	if (keycode == A)
		params->dx -= 5;
	if (keycode == S)
		params->dy -= 5;
	if (keycode == D)
		params->dz -= 5;
}

/*
This function is called in a hook, so it will wait until 
a key is pressed. If the key that is pressed matches one 
of the keycodes in the if statements an action will take place.
*/
int	key_press(int keycode, t_params	*params)
{
	if (keycode == ESC)
	{
		free(params->map->field);
		free(params->map);
		mlx_destroy_window(params->mlx, params->mlx_win);
		exit(0);
	}
	if (keycode == ARROW_U)
		params->move_y += 20;
	if (keycode == ARROW_D)
		params->move_y -= 20;
	if (keycode == ARROW_R)
		params->move_x += 20;
	if (keycode == ARROW_L)
		params->move_x -= 20;
	if (keycode == PAGE_U)
		params->elevation += 0.25;
	if (keycode == PAGE_D)
		params->elevation -= 0.25;
	key_press2(keycode, params);
	return (0);
}

int	close_win(t_params	*params)
{
	free(params->map->field);
	free(params->map);
	mlx_destroy_window(params->mlx, params->mlx_win);
	exit(0);
	return (0);
}
