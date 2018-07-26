/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:53:00 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 21:48:35 by fablin      ###    #+. /#+    ###.fr     */
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

void delant2(void *ant, size_t size)
{
	(void)size;
	if (ant)
	{
		free(ant);
	}
}

void delnode(void *node, size_t size)
{
	(void)size;
	if (node)
	{
		free(node);
	}
}

void dellink(void *link, size_t size)
{
	(void)size;
	if (link)
	{
		free(link);
	}
}

void			delenv(t_env **env)
{
	if ((*env)->file)
		ft_strdel(&(*env)->file);
	if ((*env)->ants)
		ft_lstdel(&(*env)->ants, delant2);
	if ((*env)->nodes)
		ft_lstdel(&(*env)->nodes, delnode);
	if ((*env)->links)
		ft_lstdel(&(*env)->links, dellink);
	if ((*env)->start)
		ft_delntree(&(*env)->start);
	if ((*env)->output)
		ft_strdel(&(*env)->output);
	free(*env);
	*env = NULL;
}
