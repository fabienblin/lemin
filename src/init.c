/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:44:41 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/31 16:31:57 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

void	set_ants(t_env *env)
{
	t_ant	*ant;
	t_list	*l;
	int		i;

	ant = NULL;
	i = 0;
	while (i < env->nbant)
	{
		if ((ant = newant(ft_itoa(i + 1), NULL, 0)))
		{
			l = ft_lstnew(NULL, 0);
			ft_lstpush(&env->ants, l);
			l->content = ant;
		}
		else
			exit_lemin(&env, "ERROR");
		i++;
	}
}

void	set_start_end(t_env *env)
{
	char	*node;
	char	**line;
	char	**split;

	if ((node = ft_strstr(env->file, "##start\n")))
	{
		if ((split = ft_strsplit(node + 8, '\n')) && valid_nodes(split[0]))
		{
			line = ft_strsplit(*split, ' ');
			ft_delstrsplit(&split);
			env->start = get_ntree_in_lst(line[0], env->nodes);
			ft_delstrsplit(&line);
		}
	}
	if ((node = ft_strstr(env->file, "##end\n")))
	{
		if ((split = ft_strsplit(node + 6, '\n')) && valid_nodes(split[0]))
		{
			line = ft_strsplit(*split, ' ');
			ft_delstrsplit(&split);
			env->end = get_ntree_in_lst(line[0], env->nodes);
			ft_delstrsplit(&line);
		}
	}
}

void	check_coords(t_env *env)
{
	t_list	*i;
	t_list	*j;

	i = env->nodes;
	while (i)
	{
		j = env->nodes;
		while (j)
		{
			if (j != i && !ft_memcmp((((t_ntree *)i->content)->coord),
									(((t_ntree *)j->content)->coord),
									sizeof(t_point)))
				exit_lemin(&env, "ERROR");
			j = j->next;
		}
		i = i->next;
	}
}

int		init_env(t_env *env)
{
	char	**split;

	if (env && env->file)
	{
		split = ft_strsplit(env->file, '\n');
		env->nbant = ft_atoi(split[0]);
		set_ants(env);
		set_nodes(env, split);
		check_coords(env);
		set_links(env, split);
		set_start_end(env);
		ft_delstrsplit(&split);
	}
	return (1);
}
