/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_ext.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/31 16:38:47 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/31 16:41:46 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

static int	valid_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	while (i--)
	{
		if (!ft_isalnum(name[i]))
			return (0);
	}
	return (1);
}

int			valid_ants(char *ants)
{
	int valid;

	valid = 1;
	if (ft_atoi(ants) == 0)
		valid = 0;
	return (valid);
}

int			valid_nodes(char *node)
{
	int		valid;
	char	**split;

	valid = 0;
	if (node)
	{
		valid = 1;
		split = ft_strsplit(node, ' ');
		if (split && split[0] && split[1] && split[2] && !split[3])
		{
			if ((!valid_name(split[0])) ||
				(!ft_isdigit(split[1][0])) ||
				(!ft_isdigit(split[2][0])) ||
				(split[0][0] == 'L'))
				valid = 0;
		}
		else
			valid = 0;
		ft_delstrsplit(&split);
	}
	return (valid);
}

int			valid_links(char *link)
{
	int		valid;
	char	**split;

	valid = 0;
	if (link)
	{
		valid = 1;
		split = ft_strsplit(link, '-');
		if (split && split[0] && split[1] && !split[2])
		{
			if (!valid_name(split[0]) ||
				!valid_name(split[1]))
				valid = 0;
		}
		ft_delstrsplit(&split);
	}
	return (valid);
}
