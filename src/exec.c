# include "../inc/minishell.h"

static int	get_exec(char *line, char **tab)
{
	DIR				*dir;
	struct dirent	*dirent;
	char			*str;

	if (!(dir = opendir(line)))
	{
		ft_putstr_fd("opendir error: failed to open ", 2);
		ft_putendl_fd(line, 2);
		return (0);
	}
	while ((dirent = readdir(dir)))
	{
		if (!ft_strcmp(dirent->d_name, tab[0]))
		{
			str = join_char(line, tab[0], '/');
			tab[0] = realloc_str(tab[0], str);
			ft_free(1, &str);
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

static int	find_exec(char **tab, t_env **env, int i)
{
	t_env	*tmp;
	char	**array;

	if (!env)
		return (0);
	if (tab[0][0] == '.' || tab[0][0] == '/')
		return (1);
	tmp = *env;
	while (tmp && ft_strcmp(tmp->var, "PATH"))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	array = ft_strsplit(tmp->value, ':');
	while (array[++i])
	{
		if (get_exec(array[i], tab))
		{
			ft_free_tab(array);
			return (1);
		}
	}
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(tab[0], 2);
	ft_free_tab(array);
	return (0);
}

void		ft_exec(char *line, t_env **env, int pid, int status)
{
	char	**tab;
	char	**envtab;

	tab = ft_strsplit(line, ' ');
	if (find_exec(tab, env, -1))
	{
		envtab = envlist_to_tab(env);
		pid = fork();
		if (pid == 0)
		{
			if (execve(tab[0], tab, envtab) != -1)
				ft_putchar('\n');
			else
				ft_putendl_fd(tab[0], 2);
			exit(0);
		}
		else if (pid > 0)
		{
			wait(&pid);
			if (WIFEXITED(status))
				wait(&pid);
			ft_free_tab(envtab);
			//ft_free_tab(tab);
		}
		else
			ft_putendl_fd("fork: error", 2);
	}
}