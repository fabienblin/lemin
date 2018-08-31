/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lemin.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 16:57:37 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/31 16:41:17 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <string.h>
# include <errno.h>

typedef struct	s_env
{
	char	*file;
	int		nbant;
	t_list	*ants;
	t_list	*nodes;
	t_ntree	*start;
	t_ntree	*end;
}				t_env;

typedef struct	s_ant
{
	char	*name;
	t_list	*path;
	int		start_turn;
}				t_ant;

void			exit_lemin(t_env **env, char *msg);
int				get_input(t_env *env);
int				init_env(t_env *env);
int				solve(t_env *env);
int				output(t_env *env);
t_env			*newenv(void);
void			delenv(t_env **env);
t_ant			*newant(char *name, t_list *path, int	start_turn);
void			delantlst(void *ant, size_t size);
void			ft_delstrsplit(char ***split);
int				valid_nodes(char *node);
int				valid_links(char *link);
int				valid_ants(char *ants);
void			ft_putlst(t_list *lst);
t_ntree			*get_ntree_in_lst(char *name, t_list *lst);
t_ntree			*get_ntree_in_ntree(char *name, t_ntree *t);
void 			delntreelst(void *node, size_t size);
int				ft_lstcmp(t_list *lstA, t_list *lstB, int sizeof_content);
void			set_nodes(t_env *env, char **split);
void			set_links(t_env *env, char **split);
#endif
