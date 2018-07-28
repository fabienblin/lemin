/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:44:41 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/27 23:59:32 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

t_list	*set_ants(t_env *env)
{
	t_list	*ants;
	t_ant	*ant;
	int		i;

	ants = NULL;
	ant = NULL;
	i = 0;
	while (i < env->nbant)
	{
		ant = newant(ft_itoa(i), NULL, 0);
		ft_lstpush(&ants, ft_lstnew(ant, sizeof(t_ant)));
		delant(&ant);
		i++;
	}
	return (ants);
}

int		init_env(t_env *env)
{
	char	**split;

	if (env && env->file)
	{
		split = ft_strsplit(env->file, '\n');
		env->nbant = ft_atoi(split[0]);
		env->ants = set_ants(env);
		//env->nodes = set_nodes(env, split);
		//env->links = set_links(env, split);
	}
	ft_delstrsplit(&split);
	return (1);
}
