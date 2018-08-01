/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 16:46:54 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/01 19:51:09 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_env	*env;

	env = newenv();
	get_input(env);
	init_env(env);
	solve(env);
	output(env);
	exit_lemin(&env, NULL);
	return (0);
}
