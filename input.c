/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 16:26:06 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/04/19 17:57:28 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	row_len(char const *s, char c)
{
	int	i;
	int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i + 1])
			break ;
		while (s[i] && s[i] != c)
			i++;
		nb_strs++;
	}
	return (nb_strs);
}

int	*parse_row(char *line, int len)
{
	char	**split;
	int		*row;
	int		i;

	row = (int *)malloc(sizeof(int) * len);
	if (!row)
		exit (1);
	split = ft_split(line, ' ');
	i = 0;
	while (i < len)
	{
		row[i] = ft_atoi(split[i]);
		i++;
	}
	ft_farr((void **)split);
	return (row);
}

t_map	*handle_input(int fd)
{
	char	*line;
	int		*row;
	t_map	*map;
	t_list	*list;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit(0);
	list = list_init();
	line = get_next_line(fd);
	map->w = row_len(line, ' ');
	while (line)
	{
		row = parse_row(line, map->w);
		free(line);
		list_add(list, row);
		line = get_next_line(fd);
	}
	map->h = list->len;
	map->field = (int **)list_to_array(list);
	if (!map->field)
		exit(0);
	return (map);
}
