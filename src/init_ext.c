/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_ext.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/31 16:29:09 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/31 16:36:44 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static void	set_nodes_ext(char **line, t_ntree *node, t_env *env)
{
	if ((node = ft_newntree(ft_strdup(line[0]),
							ft_newpoint(ft_atoi(line[1]), ft_atoi(line[2])),
							0,
							NULL)))
	{
		if (get_ntree_in_lst(node->name, env->nodes))
		{
			ft_delstrsplit(&line);
			exit_lemin(&env, "ERROR");
		}
		ft_lstadd(&env->nodes, ft_lstnew(NULL, 0));
		env->nodes->content = node;
	}
	ft_delstrsplit(&line);
	if (!node)
		exit_lemin(&env, "ERROR");
}

void		set_nodes(t_env *env, char **split)
{
	char	**line;
	t_ntree	*node;
	int		i;

	node = NULL;
	i = 1;
	while (split && split[i] && (split[i][0] == '#' || valid_nodes(split[i])))
	{
		if (split[i][0] != '#')
		{
			if ((line = ft_strsplit(split[i], ' ')) &&
				line[0] && line[1] && line[2] && !line[3])
				set_nodes_ext(line, node, env);
		}
		i++;
	}
}

static void	set_links_ext(char **split, t_env *env, int i)
{
	char	**line;
	t_ntree	*from;
	t_ntree	*to;

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
		exit_lemin(&env, "ERROR");
}

void		set_links(t_env *env, char **split)
{
	int	i;

	i = 1;
	while (split && split[i] && (split[i][0] == '#' || valid_nodes(split[i])))
		i++;
	while (split && split[i] && valid_links(split[i]))
	{
		if (split[i][0] != '#')
			set_links_ext(split, env, i);
		i++;
	}
}
