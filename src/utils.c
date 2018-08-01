/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/27 23:54:36 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/01 15:07:37 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

void	ft_delstrsplit(char ***split)
{
	int	i;
	
	i = 0;
	while ((*split)[i])
		ft_strdel(&(*split)[i++]);
	free(*split);
	*split = NULL;
}

void	ft_putantlst(t_list *lst)
{
	while (lst)
	{
		ft_printf("name = '%s'\tpath = %p\tstart_turn = %d\n",
				((t_ant *)lst->content)->name,
				((t_ant *)lst->content)->path,
				((t_ant *)lst->content)->start_turn);
		lst = lst->next;
	}
}

void	ft_putntreelst(t_list *lst)
{
	while (lst)
	{
		ft_printf("name = '%s'\tcoord = %p\tdepth = %d\tbsons = %d\n",
				((t_ntree *)lst->content)->name,
				((t_ntree *)lst->content)->coord,
				((t_ntree *)lst->content)->depth,
				((t_ntree *)lst->content)->nbsons);
		lst = lst->next;
	}
}

t_ntree	*get_ntree_in_lst(char *name, t_list *lst)
{
	while (lst)
	{
		if (ft_strcmp(((t_ntree *)lst->content)->name, name) == 0)
			return ((t_ntree *)lst->content);
		lst = lst->next;
	}
	return (NULL);
}

t_ntree	*get_ntree_in_ntree(char *name, t_ntree *t)
{
	int			i;

	if (ft_strcmp(t->name, name) == 0)
		return (t);
	else
	{
		i = 0;
		while (i < t->nbsons)
		{
			return (get_ntree_in_ntree(name, ((t_ntree *)t->sons->next)));
			i++;
		}
		return (NULL);
	}
}