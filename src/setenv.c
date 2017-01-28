# include "../inc/minishell.h"

void	ft_setenv(char *line, t_env	**env)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (!tab[1] && env)
		display_list(env);
	else if (tab[1] && tab[2] && tab[3])
		ft_putendl_fd("minishell/setenv: Too many arguments.", 2);
	else
		add_env_elem(env, tab[1], tab[2]);
	ft_free_tab(tab);
}