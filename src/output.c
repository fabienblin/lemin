/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   output.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:49:42 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 21:18:58 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

t_list	*get_path_i(int i, t_list *path)
{
	while (i > 0 && path)
	{
		path = path->next;
		i--;
	}
	return (path);
}

int		nbturns(t_env *env)
{
	int		nbturn;
	t_list	*ant_lst;

	ant_lst = env->ants;
	while (ant_lst && ant_lst->next)
		ant_lst = ant_lst->next;
	nbturn = ft_lstlen(((t_ant *)ant_lst->content)->path) +
		((t_ant *)ant_lst->content)->start_turn;
	return (nbturn);
}

void	put_ants_from_turn_i(int i, t_env *env, int nbturn)
{
	t_list	*ant_lst;
	t_ant	*ant;
	t_list	*node;

	ant_lst = env->ants;
	while (ant_lst && i > ((t_ant *)ant_lst->content)->start_turn)
	{
		if ((ant = (t_ant *)ant_lst->content) &&
			(node = get_path_i(i - ant->start_turn, ant->path)))
		{
			ft_printf("L%s-%s", ant->name, ((t_ntree *)node->content)->name);
			if (ant_lst->next)
				ft_printf(" ");
		}
		ant_lst = ant_lst->next;
	}
	if (i < nbturn)
		ft_printf("\n");
}

void	putlemin(t_env *env)
{
	int		nbturn;
	int		i;

	nbturn = nbturns(env);
	i = 0;
	while (i < nbturn)
	{
		put_ants_from_turn_i(i, env, nbturn);
		i++;
	}
}

int		output(t_env *env)
{
	ft_printf("%s", env->file);
	putlemin(env);
	return (1);
}
