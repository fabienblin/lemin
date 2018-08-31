/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:47:40 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/31 19:50:17 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

int		valid_start_end_ext(char *start, char *end)
{
	char	**split;
	int		valid;

	valid = 1;
	split = ft_strsplit(start + 8, '\n');
	if (!valid_nodes(*split))
		valid = 0;
	ft_delstrsplit(&split);
	split = ft_strsplit(end + 6, '\n');
	if (!valid_nodes(*split))
		valid = 0;
	ft_delstrsplit(&split);
	return (valid);
}

int		valid_start_end(char *file)
{
	int		valid;
	char	*start;
	char	*end;

	valid = 0;
	if (file)
	{
		valid = 1;
		start = ft_strstr(file, "##start\n");
		end = ft_strstr(file, "##end\n");
		if (start && end)
			valid = valid_start_end_ext(start, end);
		else
			valid = 0;
	}
	return (valid);
}

int		valid_file_ext(char **split)
{
	int		valid;
	int		i;

	valid = 1;
	i = 1;
	while (valid && split[i])
	{
		if (split[i][0] != '#')
		{
			valid = valid_nodes(split[i]);
			if (valid == 0)
				valid = valid_links(split[i]);
		}
		i++;
	}
	while (valid && split[i])
	{
		valid = valid_links(split[i]);
		i++;
	}
	return (valid);
}

int		valid_file(char *file)
{
	int		valid;
	char	**split;

	valid = 0;
	if (file)
	{
		valid = 1;
		split = ft_strsplit(file, '\n');
		if (valid && !valid_start_end(file))
			valid = 0;
		if (valid && !valid_ants(split[0]))
			valid = 0;
		if (valid && !valid_file_ext(split))
			valid = 0;
		ft_delstrsplit(&split);
	}
	return (valid);
}

int		get_input(t_env *env)
{
	char	*line;
	int		gnl;

	while ((gnl = get_next_line(0, &line)) > 0)
	{
		if (!ft_strlen(line))
			break ;
		if (!(env->file = ft_strjoinfree(env->file, line)) ||
			!(env->file = ft_strjoinfree(env->file, ft_strdup("\n"))))
			return (-1);
	}
	if (gnl == -1 || !valid_file(env->file))
		exit_lemin(&env, "ERROR");
	return (gnl);
}
