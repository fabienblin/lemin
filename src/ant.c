/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 21:16:46 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 21:40:18 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

t_ant	*newant(char *id, t_list *path, int	start_turn)
{
	t_ant	*new;

	if (!(new = (t_ant *)malloc(sizeof(t_ant))))
		return (NULL);
	ft_bzero(new, sizeof(t_ant));
	if (id)
		new->id = id;
	if (path)
		new->path = path;
	new->start_turn = start_turn;
	return (new);
}

void delpath(void *path, size_t size)
{
	(void)size;
	if (path)
	{
		free(path);
	}
}

void	delant(t_ant **ant)
{
	if (ant && *ant)
	{
		if ((*ant)->id)
			ft_strdel(&(*ant)->id);
		if ((*ant)->path)
			ft_lstdel(&(*ant)->path, delpath);
		free(*ant);
		ant = NULL;
	}
}