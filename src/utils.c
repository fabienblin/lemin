/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/27 23:54:36 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 21:05:51 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

void	ft_delstrsplit(char ***split)
{
	int	i;

	i = 0;
	if (split && *split)
	{
		while ((*split)[i])
			ft_strdel(&(*split)[i++]);
		free(*split);
		*split = NULL;
	}
}

int		ft_lstcmp(t_list *lsta, t_list *lstb, int sizeof_content)
{
	while (lsta && lstb &&
		!ft_memcmp(lsta->content, lstb->content, sizeof_content))
	{
		lsta = lsta->next;
		lstb = lstb->next;
	}
	if (!lsta && !lstb)
		return (0);
	return (1);
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
