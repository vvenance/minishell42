# include "../inc/minishell.h"

static void	echo_dollar(char *line, t_env **env)
{
	t_env	*tmp;
	char	*str;

	tmp = *env;
	str = ft_strsub(line, 1, ft_strlen(line) - 1);
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->var))
		{
			ft_putstr(tmp->value);
			break;
		}
		tmp = tmp->next;
	}
	ft_free(1, &str);
}

static void	echo_quote(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '\"')
			ft_putchar(line[i]);
	}
}

void		ft_echo(char *line, t_env **env)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(line, ' ');
	i = 0;
	if (!ft_strcmp(tab[1], "-n"))
		i += 1;
	while (tab[++i])
	{
		if (tab[i][0] == '\"')
			echo_quote(tab[i]);
		else if (tab[i][0] == '$')
			echo_dollar(tab[i], env);
		else
			ft_putstr(tab[i]);
		if (tab[i + 1])
			ft_putchar(' ');
	}
	if (ft_strcmp(tab[1], "-n"))
		ft_putendl("");
	ft_free_tab(tab);
}
