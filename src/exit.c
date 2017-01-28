# include "../inc/minishell.h"

void	ft_exit(t_env **env, char *line)
{
	clear_env(env);
	ft_free(2, &line);
}