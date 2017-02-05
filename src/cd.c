# include "../inc/minishell.h"

static t_cd	*init_cd(t_cd *cd)
{
	cd = malloc(sizeof(t_cd));
	cd->home = NULL;
	cd->pwd = NULL;
	cd->oldpwd = NULL;
	return (cd);
}

static void	find_cd_var(t_cd **cd, t_env **env)
{
	t_env *tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->var, "HOME"))
			(*cd)->home = tmp;
		if (!ft_strcmp(tmp->var, "PWD"))
			(*cd)->pwd = tmp;
		if (!ft_strcmp(tmp->var, "OLDPWD"))
			(*cd)->oldpwd = tmp;
		tmp = tmp->next;
	}
	if ((*cd)->pwd == NULL)
		add_env_elem(env, "PWD", NULL);
	if ((*cd)->oldpwd == NULL)
		add_env_elem(env, "OLDPWD", NULL);
	if ((*cd)->home == NULL)
		add_env_elem(env, "HOME", NULL);
	if ((*cd)->pwd == NULL || (*cd)->oldpwd == NULL || (*cd)->home == NULL)
		find_cd_var(cd, env);
}

static void	error_chdir(char *path)
{
	if (access(path, F_OK) == -1)
	{
		ft_putstr_fd("minishell/cd: no such file or directory: ", 2);
		ft_putendl_fd(path, 2);
	}
	else
		ft_putendl_fd("cd: you don't have the rights to access the file", 2);
}

static void	norme_cd(char **tab, t_cd *cd)
{
	if (tab[1] == NULL)
	{
		if (!cd->home->value || !ft_strcmp(cd->home->value, "(null)"))
			ft_putendl_fd("minishell/cd: cd: HOME not set", 2);
		else
		{
			if (chdir(cd->home->value) == -1)
				error_chdir(cd->home->value);
			else
			{
				cd->oldpwd->value = realloc_str(cd->oldpwd->value, cd->pwd->value);
				cd->pwd->value = realloc_str(cd->pwd->value, cd->home->value);
			}
		}
	}
	else if (tab[1][0] == '-' && !tab[1][1])
	{
		if (!cd->oldpwd->value || !ft_strcmp(cd->oldpwd->value, "(null)") ||
			!ft_strcmp(cd->pwd->value, "(null)"))
			ft_putendl_fd("minishell/cd: cd: OLDPWD or PWD not set", 2);
		else if (chdir(cd->oldpwd->value) == -1)
			error_chdir(cd->oldpwd->value);
		else
			str_swap(&cd->pwd->value, &cd->oldpwd->value);
	}
}

void		ft_cd(char *line, t_env **env)
{
	char	**tab;
	t_cd	*cd;

	tab = ft_strsplit(line, ' ');
	cd = init_cd(cd);
	if (tab[1] != NULL && tab[2] != NULL)
 		ft_putendl_fd("minishell/cd: too many arguments", 2);
 	find_cd_var(&cd, env);
 	if (tab[1] == NULL || !ft_strcmp(tab[1], "-"))
		norme_cd(tab, cd);
	else
	{
		if (chdir(tab[1]) == -1)
			error_chdir(tab[1]);
		else
		{
			cd->tmp.value = ft_memalloc(400);
			getcwd(cd->tmp.value, 399);
			cd->oldpwd->value = realloc_str(cd->oldpwd->value, cd->pwd->value);
			cd->pwd->value = realloc_str(cd->pwd->value, cd->tmp.value);
			ft_free(1, &cd->tmp.value);
		}
	}
	ft_free(1, &cd);
 	ft_free_tab(tab);
}
