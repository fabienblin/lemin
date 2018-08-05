/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:50:24 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/05 18:56:16 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

t_list	*dijkstra(t_ntree *dest, t_ntree *current, t_list *path, t_list *best_path)
{
	t_list		*son;

	son = current->sons;
	if (!ft_strcmp(current->name, dest->name) && (ft_lstlen(best_path) == 0 || ft_lstlen(path) < ft_lstlen(best_path)))
	{
		best_path = path;
		ft_putntreelst(best_path);
		return (best_path);
	}
	while (son)
	{
		if (!get_ntree_in_lst(((t_ntree *)son->content)->name, path))
		{
			ft_lstpush(&path, ft_lstnew(son->content, sizeof(t_ntree)));
			path = dijkstra(dest, (t_ntree *)son->content, path, best_path);
			return (path);
		}
		son = son->next;
	}
	return (best_path);
}

int				solve(t_env *env)
{
	t_list *a = dijkstra(env->end, env->start, NULL, NULL);
	ft_printf("SOLVE==================\n");
	ft_putntreelst(a);
	return (1);
}
