/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:50:24 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 18:15:52 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

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

t_list	*get_ntree_in_ants_turn(char *name, t_list *ants, int turn)
{
	t_ant	*ant;
	t_list	*node;
	int		i;

	while (ants && ants->next && (ant = (t_ant *)ants->content))
	{
		node = ant->path;
		i = -1 + ant->start_turn;
		while (node && i < turn)
		{
			node = node->next;
			i++;
		}
		if (node && i == turn)
		{
			if (ft_strcmp(((t_ntree *)node->content)->name, name) == 0)
				return (node);
		}
		ants = ants->next;
	}
	return (NULL);
}

int		is_path_used(char *name, t_env *env, int turn, t_list *path)
{
	if (!ft_strcmp(name, env->end->name))
		return (0);
	if (get_ntree_in_ants_turn(name, env->ants, turn) ||
		get_ntree_in_lst(name, path))
		return (1);
	return (0);
}

t_list	*dijkstra(t_env *env, t_ntree *current, int turn, t_list *path, t_list **best_path)
{
	t_list			*son;

	ft_lstadd(&path, ft_lstnew(current, sizeof(t_ntree)));
	if (!ft_strcmp(current->name, env->end->name) && (ft_lstlen(*best_path) == 0 || ft_lstlen(path) <= ft_lstlen(*best_path)))
	{
		ft_lstdel(best_path, NULL);
		*best_path = ft_lstdup(path);
	}
	else
	{
		son = current->sons;
		while (son)
		{
			if (!is_path_used(((t_ntree *)son->content)->name, env, turn, path))
				dijkstra(env, (t_ntree *)son->content, turn + 1, path, best_path);
			son = son->next;
		}
	}
	ft_lstdelfirst(&path, NULL);
	return (*best_path);
}

int		solve(t_env *env)
{
	t_list	*ant;

	ant = env->ants;
	if (!(dijkstra(env, env->start, ((t_ant *)ant->content)->start_turn, NULL, &((t_ant *)ant->content)->path)))
		exit_lemin(&env, "ERROR");
	ant = ant->next;
	while (ant)
	{
		if (!(dijkstra(env, env->start, ((t_ant *)ant->content)->start_turn, NULL, &((t_ant *)ant->content)->path)))
			((t_ant *)ant->content)->start_turn++;
		else
			ant = ant->next;
	}
	return (1);
}
