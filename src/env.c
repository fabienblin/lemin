/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:53:00 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/01 17:21:11 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

t_env			*newenv(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	ft_bzero(env, sizeof(t_env));
	return (env);
}

void delntreelst(void *node, size_t size)
{
	(void)size;
	if (node)
	{
		if (((t_ntree *)node)->name)
			ft_strdel(&((t_ntree *)node)->name);
		if (((t_ntree *)node)->coord)
			ft_delpoint(&((t_ntree *)node)->coord);
		if (((t_ntree *)node)->sons)
			ft_lstdel(&((t_ntree *)node)->sons, NULL);
	}
}

void			delenv(t_env **env)
{
	if ((*env)->file)
		ft_strdel(&(*env)->file);
	if ((*env)->ants)
		ft_lstdel(&(*env)->ants, delantlst);
	if ((*env)->nodes)
		ft_lstdel(&(*env)->nodes, delntreelst);
	if ((*env)->output)
		ft_strdel(&(*env)->output);
	free(*env);
	*env = NULL;
}
