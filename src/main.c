/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 16:46:54 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 21:32:09 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

void	exit_lemin(t_env **env)
{
	ft_strdel(&(*env)->file);
	free(*env);
	*env = NULL;
	if (errno)
		ft_exit(strerror(errno));
}

char	*ft_strjoinfree2(char **s1, char **s2)
{
	char	*join;

	if (!(join = ft_strjoin(*s1, *s2)))
		return (NULL);
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (join);
}

int		get_input(t_env *env)
{
	char	*line;
	int		gnl;

	while ((gnl = get_next_line(0, &line)) > 0)
	{
		if (!(env->file = ft_strjoinfree(env->file, line)) ||
			!(env->file = ft_strjoinfree(env->file, ft_strdup("\n"))))
			return (-1);
	}
	if (gnl == -1)
		ft_exit("GNL FAIL !");
	return (gnl);
}

int		init_env(t_env *env)
{
	env->file = ft_strnew(0);
	return (1);
}

int		main(void)
{
	//get input
	t_env	*env = (t_env *)malloc(sizeof(t_env));
	
	init_env(env);
	get_input(env);
	ft_printf("%s", env->file);
	exit_lemin(&env);
	return (0);
}