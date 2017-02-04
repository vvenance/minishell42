# include "../inc/minishell.h"

void	ft_exit(t_env **env, char *line, t_env **tmpenv)
{
	clear_env(env);
	ft_free(1, &line);
	exit(0);
}