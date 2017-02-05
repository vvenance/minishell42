/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:13:34 by vvenance          #+#    #+#             */
/*   Updated: 2017/02/05 15:13:37 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	builtin_or_exec(char *line, t_env **env, t_env **tmpenv)
{
	if (line[0] == 'e' && !ft_strncmp(line, "echo", 4) && (line[4] == ' ' ||
		!line[4]))
		ft_echo(line, env);
	else if (line[0] == 'e' && !ft_strcmp(line, "exit") && !line[4])
		ft_exit(env, line, tmpenv);
	else if (*env == NULL && (!ft_strncmp("cd", line, 2) ||
		!ft_strncmp("env", line, 3) || !ft_strncmp("setenv", line, 6) ||
		!ft_strncmp("unsetenv", line, 8)))
		ft_putendl_fd("minishell: no env defined.", 2);
	else if (line[0] == 's' && !ft_strncmp(line, "setenv", 6) && (!line[6] ||
		line[6] == ' '))
		ft_setenv(line, env);
	else if (line[0] == 'e' && !ft_strncmp(line, "env", 3) && (!line[3] ||
		line[3] == ' '))
		ft_env(line, env, tmpenv, 0);
	else if (line[0] == 'c' && !ft_strncmp(line, "cd", 2) && (!line[2] ||
		line[2] == ' '))
		ft_cd(line, env);
	else if (line[0] == 'u' && !ft_strncmp(line, "unsetenv", 8) &&
		(!line[8] || line[8] == ' '))
		ft_unsetenv(line, env);
	else
		ft_exec(line, env, 0, 0);
}
