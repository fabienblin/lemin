/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:44:41 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/01 19:58:54 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

void	set_ants(t_env *env)
{
	t_ant	*ant;
	int		i;

	ant = NULL;
	i = 0;
	while (i < env->nbant)
	{
		if ((ant = newant(ft_itoa(i), NULL, 0)))
		{
			ft_lstadd(&env->ants, ft_lstnew(NULL, 0));
			env->ants->content = ant;
		}
		i++;
	}
}

void	set_nodes(t_env *env, char **split)
{
	char	**line;
	t_ntree	*node;
	int		i;

	node = NULL;
	i = 1;
	while (split && split[i] && valid_nodes(split[i]))
	{
		if (split[i][0] != '#')
		{
			if ((line = ft_strsplit(split[i], ' ')) && line[0] && line[1] && line[2] && !line[3] &&
				(node = ft_newntree(ft_strdup(line[0]),
									ft_newpoint(ft_atoi(line[1]), ft_atoi(line[2])),
									0,
									NULL)))
			{
				ft_lstadd(&env->nodes, ft_lstnew(NULL, 0));
				env->nodes->content = node;
			}
			ft_delstrsplit(&line);
		}
		i++;
	}
}

void	set_links(t_env *env, char **split)
{
	char	**line;
	t_ntree	*from;
	t_ntree	*to;
	int		i;

	i = 1;
	while (split && split[i] && valid_nodes(split[i]))
		i++;
	while (split && split[i] && valid_links(split[i]))
	{
		if (split[i][0] != '#')
		{
			if ((line = ft_strsplit(split[i], '-')) && line[0] && line[1] && !line[2] &&
				(from = get_ntree_in_lst(line[0], env->nodes)) &&
				(to = get_ntree_in_lst(line[1], env->nodes)))
			{
				ft_lstadd(&from->sons, ft_lstnew(NULL, 0));
				ft_lstadd(&to->sons, ft_lstnew(NULL, 0));
				from->sons->content = to;
				to->sons->content = from;
				from->nbsons++;
				to->nbsons++;
			}
			ft_delstrsplit(&line);
		}
		i++;
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
		set_links(env, split);
	}
	ft_delstrsplit(&split);
	return (1);
}
