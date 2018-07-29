/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/27 23:54:36 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/29 15:29:02 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

void	ft_delstrsplit(char ***split)
{
	int	i;
	
	i = 0;
	while ((*split)[i])
		ft_strdel(&(*split)[i++]);
	free(*split);
	*split = NULL;
}

void	ft_putlst(t_list *lst)
{
	while (lst)
	{
		ft_printf("name = '%s'\npath = %p\nstart_turn = %d\n",
				((t_ant *)lst->content)->name,
				((t_ant *)lst->content)->path,
				((t_ant *)lst->content)->start_turn);
		lst = lst->next;
	}
}