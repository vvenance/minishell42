/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:09:58 by vvenance          #+#    #+#             */
/*   Updated: 2016/11/30 13:10:00 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/inc/libft.h"

typedef struct		s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_cd
{
	t_env			*oldpwd;
	t_env			*pwd;
	t_env			*home;
	t_env			tmp;
}					t_cd;

void	builtin_or_exec(char *line, t_env **env, t_env **tmpenv);
void		ft_cd(char *line, t_env **env);
void		ft_echo(char *line, t_env **env);
void		ft_env(char *line, t_env **env, t_env **tmpenv, int i);
void		ft_exec(char *line, t_env **env, int pid, int status);
void	ft_exit(t_env **env, char *line);
void	ft_setenv(char *line, t_env	**env);
void	ft_unsetenv(char *line, t_env **env);
void	del_env_elem(t_env **env, char *data);
void	add_env_elem(t_env **env, char *name, char *value);
void	clear_env(t_env **env);
char	**envlist_to_tab(t_env **env);
void	envtab_to_list(char **envtab, t_env **env);
void	ft_free_tab(char **tab);
char	*join_char(char *str, char *str2, char c);
void	display_list(t_env **env);
void	display_tab(char **envtab);
char	*clean_user_entry(char *str);
char	*realloc_str(char *str, char *newstr);
void	str_swap(char **str, char **str2);
char	*str_join_char(char *str1, char *str2, char c);

#endif