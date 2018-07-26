/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:42:56 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 19:09:18 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

void	exit_lemin(t_env **env, char *msg)
{
	delenv(env);
	if (errno)
		ft_exit(strerror(errno));
	else
		ft_exit(msg);
}