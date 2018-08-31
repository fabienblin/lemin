/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 21:16:46 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 21:21:11 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

t_ant	*newant(char *name, t_list *path, int start_turn)
{
	t_ant	*new;

	new = ft_memalloc(sizeof(t_ant));
	if (name)
		new->name = name;
	if (path)
		new->path = path;
	new->start_turn = start_turn;
	return (new);
}

void	delantlst(void *ant, size_t size)
{
	(void)size;
	if (ant)
	{
		if (((t_ant *)ant)->name)
			ft_strdel(&((t_ant *)ant)->name);
		if (((t_ant *)ant)->path)
			ft_lstdel(&((t_ant *)ant)->path, NULL);
	}
}
