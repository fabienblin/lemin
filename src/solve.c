/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:50:24 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/09 17:58:15 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

void	ft_lstdellast(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*prev;
	
	lst = *alst;
	prev = NULL;
	while (lst)
	{
		if (lst->next == NULL)
		{
			if (del)
				del(lst->content, lst->content_size);
			ft_memdel((void **)&lst);
			if (prev)
				prev->next = NULL;
			return ;
		}
		else
		{
			prev = lst;
			lst = lst->next;
		}
	}
}

void	ft_delfirst(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	
	lst = *alst;
	*alst = lst->next;
	if (del)
		del(lst->content, lst->content_size);
	free (lst->content);
	ft_memdel((void **)&lst);
}

t_list	*dijkstra(t_ntree *dest, t_ntree *current, t_list **best_path)
{
	t_list			*son;
	static t_list	*path = NULL;

	son = current->sons;
	ft_lstadd(&path, ft_lstnew(current, sizeof(t_ntree)));
	if (!ft_strcmp(current->name, dest->name) && (ft_lstlen(*best_path) == 0 || ft_lstlen(path) < ft_lstlen(*best_path)))
	{
		ft_lstdel(best_path, NULL);
		*best_path = ft_lstdup(path);
	}
	else
	{
		while (son)
		{
			if (!get_ntree_in_lst(((t_ntree *)son->content)->name, path))
				dijkstra(dest, (t_ntree *)son->content, best_path);
			son = son->next;
		}
	}
	ft_delfirst(&path, NULL);
	return (*best_path);
}

int				solve(t_env *env)
{
	t_list *best = NULL;
	best = dijkstra(env->end, env->start, &best);
	ft_putntreelst(best);
	ft_lstdel(&best, NULL);
	return (1);
}
