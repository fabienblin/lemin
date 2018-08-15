/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:50:24 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/15 18:48:31 by fablin      ###    #+. /#+    ###.fr     */
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

void	ft_lstdelfirst(t_list **alst, void (*del)(void *, size_t))
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
	ft_lstdelfirst(&path, NULL);
	return (*best_path);
}

t_list	*get_ntree_in_ants_turn(char *name, t_list *ants, int turn)
{
	t_ant	*ant;
	t_list	*node;
	int		i;

	if (*name == 'E')
		return (NULL);
	while (ants && ants->next && (ant = (t_ant *)ants->content))
	{
		node = ant->path;
		i = 0;
		while (node && i++ < turn)
		{
			node = node->next;
		}
		if (i == turn)
		{
			if (node && ft_strcmp(((t_ntree *)node->content)->name, name) == 0)
				return (node);
		}
		ants = ants->next;
	}
	return (NULL);
}

int		is_path_used(char *name, t_list *ants, int turn, t_list *path)
{
	if (get_ntree_in_ants_turn(name, ants, turn) &&
		get_ntree_in_lst(name, path))
		return (1);
	return (0);
}

t_list	*dijkstra2(t_env *env, t_ntree *current, t_list **best_path, int turn)
{
	t_list			*son;
	static t_list	*path = NULL;

	son = current->sons;
	ft_lstadd(&path, ft_lstnew(current, sizeof(t_ntree)));
	if (!ft_strcmp(current->name, env->end->name))// && (ft_lstlen(*best_path) == 0 || ft_lstlen(path) >= ft_lstlen(*best_path)))
	{
		ft_lstdel(best_path, NULL);
		*best_path = ft_lstdup(path);
	}
	else
	{
		while (son)
		{
			if (!is_path_used(((t_ntree *)son->content)->name, env->ants, turn, path))
				dijkstra2(env, (t_ntree *)son->content, best_path, turn + 1);
			son = son->next;
		}
	}
	ft_lstdelfirst(&path, NULL);
	return (*best_path);
}

int		solve(t_env *env)
{
	t_list	*path = NULL;
	t_list	*ant;
	
	ant = env->ants;
	((t_ant *)ant->content)->path = dijkstra(env->end, env->start, &path);
	ant = ant->next;
	while (ant)
	{
		((t_ant *)ant->content)->path = dijkstra2(env, env->start, &path, 0);
		//((t_ant *)ant->content)->path = dijkstra(env->end, env->start, &path);
		ft_putntreelst(((t_ant *)ant->content)->path);
		ft_printf("--------------------\n");
		ant = ant->next;
	}
	return (1);
}
