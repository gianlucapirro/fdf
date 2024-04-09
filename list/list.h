/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 11:02:55 by gpirro        #+#    #+#                 */
/*   Updated: 2022/04/21 11:02:57 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_elem {
	struct s_elem	*next;
	struct s_elem	*prev;
	struct s_pos	*pos;
	void			*data;

}	t_elem;

typedef struct s_list {
	struct s_elem	*top;
	int				len;
}	t_list;

typedef struct s_field
{
	void	**array;
	int		len;
	int		width;
}	t_field;

t_list	*list_init(void);
void	free_list(t_list *list, int free_data);
void	*list_add(t_list *list, void *data);
void	*pop(t_list *list);
void	*get(t_list	*list, int pos);
void	*insert(t_list *list, void *data);
void	*insert_i(t_list *list, void *data, int i);
t_list	*str_array_to_list(char **array);
t_list	*list_atoi(t_list *list);
int		*list_to_int_array(t_list *list);
void	**list_to_array(t_list *list);

#endif
