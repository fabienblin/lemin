/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   output.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 16:49:42 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/04 19:42:42 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

int				output(t_env *env)
{
	ft_printf("FILE==================\n");
	ft_printf("%s\n", env->file);
	ft_printf("NBANTS==================\n");
	ft_printf("nbant = %d\n", env->nbant);
	ft_printf("START=END==================\n");
	ft_put_start_end(env);
	ft_printf("TREE==================\n");
	ft_putntreelst(env->nodes);
	ft_printf("ANTS==================\n");
	ft_putantlst(env->ants);
	return (1);
}