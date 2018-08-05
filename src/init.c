/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:44:41 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/04 21:24:12 by fablin      ###    #+. /#+    ###.fr     */
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
		else
			exit_lemin(&env, "Invalid ants.");
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
				if (get_ntree_in_lst(node->name, env->nodes))
				{
					ft_delstrsplit(&line);
					exit_lemin(&env, "Node allready declared.");
				}
				ft_lstadd(&env->nodes, ft_lstnew(NULL, 0));
				env->nodes->content = node;
			}
			ft_delstrsplit(&line);
			if (!node)
				exit_lemin(&env, "Invalid node.");
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
			if (!from || !to)
				exit_lemin(&env, "Invalid link.");
		}
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
		split = ft_strsplit(node + 8, '\n');
		line = ft_strsplit(*split, ' ');
		ft_delstrsplit(&split);
		env->start = get_ntree_in_lst(line[0], env->nodes);
		ft_delstrsplit(&line);
	}
	if ((node = ft_strstr(env->file, "##end\n")))
	{
		split = ft_strsplit(node + 6, '\n');
		line = ft_strsplit(*split, ' ');
		ft_delstrsplit(&split);
		env->end = get_ntree_in_lst(line[0], env->nodes);
		ft_delstrsplit(&line);
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
		while(j)
		{
			if (j != i && !ft_memcmp((char *)(((t_ntree *)i->content)->coord),
									(char *)(((t_ntree *)j->content)->coord),
									sizeof(t_point)))
				exit_lemin(&env, "Node coords are identical.");
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
	}
	ft_delstrsplit(&split);
	return (1);
}
