/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/27 23:54:36 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/20 17:22:38 by fablin      ###    #+. /#+    ###.fr     */
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

int		ft_lstcmp(t_list *lstA, t_list *lstB, int sizeof_content)
{
	while (lstA && lstB && !ft_memcmp(lstA->content, lstB->content, sizeof_content))
	{
		lstA = lstA->next;
		lstB = lstB->next;
	}
	if (!lstA && !lstB)
		return (0);
	return (1);
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
	while (lst && lst->content)
	{
		ft_printf("name = '%s'\tcoord = %p\tdepth = %d\tnbsons = %d\n",
				((t_ntree *)lst->content)->name,
				((t_ntree *)lst->content)->coord,
				((t_ntree *)lst->content)->depth,
				((t_ntree *)lst->content)->nbsons);
		lst = lst->next;
	}
}

void	ft_put_start_end(t_env *env)
{
	if (env->start){
	ft_printf("start :\tname = '%s'\tcoord = %p\tdepth = %d\tnbsons = %d\n",
			env->start->name,
			env->start->coord,
			env->start->depth,
			env->start->nbsons);}
	if (env->end){
	ft_printf("end :\tname = '%s'\tcoord = %p\tdepth = %d\tnbsons = %d\n",
			env->end->name,
			env->end->coord,
			env->end->depth,
			env->end->nbsons);}
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