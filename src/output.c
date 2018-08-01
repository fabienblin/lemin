/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   output.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:49:42 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/01 15:40:42 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

int				output(t_env *env)
{
	ft_printf("%s\n", env->file);
	ft_printf("nbant = %d\n", env->nbant);
	ft_putntreelst(env->nodes);
	ft_putantlst(env->ants);
	return (1);
}