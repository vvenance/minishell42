# include "../inc/minishell.h"

void	ft_unsetenv(char *line, t_env **env)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(line, ' ');
	if (!tab[1])
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
	else
	{
		i = 0;
		while (tab[++i])
			del_env_elem(env, tab[i]);
	}
	ft_free_tab(tab);
}