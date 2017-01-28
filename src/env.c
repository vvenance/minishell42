# include "../inc/minishell.h"

static void	cpy_env(t_env **env, t_env **tmpenv)
{
	t_env *tmp;

	tmp = *env;
	while (tmp)
	{
		add_env_elem(tmpenv, tmp->var, tmp->value);
		tmp = tmp->next;
	}
}

static int	find_equal(char	**pairval, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
	{
		pairval = ft_strsplit(str, '=');
		return (1);
	}
	return (0);
}

static void	wich_display(t_env **env, t_env **tmpenv)
{
	if (*tmpenv == NULL)
			display_list(env);
	else
		display_list(tmpenv);
}

static void	free_var(char **tab, t_env **tmpenv)
{
	clear_env(tmpenv);
	ft_free_tab(tab);
}

void		ft_env(char *line, t_env **env, t_env **tmpenv, int i)
{
	char	**tab;
	int		j;
	char	**pairval;

	tab = NULL;
	tab = ft_strsplit(line, ' ');
	j = 0;
	while (tab[j])
	{
		ft_putendl(tab[j]);
		j++;
	}
	if (tab[1] && ft_strcmp(tab[1], "-i"))
		cpy_env(env, tmpenv);
	else
		i+= 1;
	while (tab[++i] && find_equal(pairval, tab[i]))
	{
		add_env_elem(tmpenv, pairval[0], pairval[1]);
		ft_free_tab(pairval);
	}
	if (!tab[i])
		wich_display(env, tmpenv);
	else
	{
		j = i;
		while (tab[++i])
			tab[j] = str_join_char(tab[j], tab[i], ' ');
		builtin_or_exec(tab[j], tmpenv, NULL);
	}
	free_var(tab, tmpenv);
}