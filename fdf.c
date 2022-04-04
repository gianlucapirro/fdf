/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:35:24 by gpirro        #+#    #+#                 */
/*   Updated: 2022/04/04 16:33:49 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
draws a pixel on the screen and checks if the x and y are still in the Image
 */
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WINDOW_WIDTH - 1 || x < 0 || y > WINDOW_HEIGHT - 1 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
 This function renders every frame. 
 This function is called in a loop (mlx_hook_loop) 
 so that it will draw to the image for every frame.
 */
int	render_next_frame(void *tmp)
{
	t_data		img;
	t_params	*params;

	params = (t_params *)(tmp);
	img.img = mlx_new_image(params->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	draw_map(params, &img);
	mlx_put_image_to_window(params->mlx, params->mlx_win, img.img, 0, 0);
	free(img.img);
	free(img.addr);
	return (1);
}

/*
 Sets all the values of the struct params
*/
void	params_init(t_params *params, void *mlx, void *mlx_win, t_map *map)
{
	params->mlx = mlx;
	params->mlx_win = mlx_win;
	params->map = map;
	params->zoom = 25;
	params->move_y = WINDOW_HEIGHT / 2;
	params->move_x = WINDOW_WIDTH / 2;
	params->dx = 0;
	params->dy = 0;
	params->dz = 0;
	params->deg = 30;
	params->elevation = 1;
}

/*
Handles wrong input so that it gives a correct
error message and exits the program.
*/
void	error_handling(int argc, int fd)
{
	if (argc == 1)
		ft_printf("ERROR: \"NO MAP WAS PASSED AS AN ARGUMENT\"\n");
	else if (argc > 2)
		ft_printf("ERROR \"PLEASE GIVE ONLY ONE MAP AS AN ARGUMENT\"\n");
	else if (fd == -1)
		ft_printf("ERROR \"MAP WAS NOT FOUND\"\n");
	else
		return ;
	exit (0);
}

int	main(int argc, char *argv[])
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_params	params;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	error_handling(argc, fd);
	map = handle_input(fd);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF!");
	params_init(&params, mlx, mlx_win, map);
	mlx_hook(mlx_win, 2, 1L << 0, key_press, &params);
	mlx_hook(mlx_win, 17, 0, &close_win, &params);
	mlx_loop_hook(mlx, render_next_frame, &params);
	mlx_loop(mlx);
	return (0);
}
