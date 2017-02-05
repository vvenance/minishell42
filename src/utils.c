/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:15:37 by vvenance          #+#    #+#             */
/*   Updated: 2017/02/05 15:15:53 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	del_env_elem(t_env **env, char *data)
{
	t_env	*tmp;
	t_env	*prev;

	prev = NULL;
	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(data, tmp->var))
		{
			if (!prev)
				env = &tmp->next;
			else
				prev->next = tmp->next;
			ft_free(3, &tmp->var, &tmp->value, &tmp);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	add_env_elem(t_env **env, char *name, char *value)
{
	t_env	*tmp;
	t_env	*new;

	tmp = *env;
	new = NULL;
	while (tmp && tmp->next && tmp->var && ft_strcmp(tmp->var, name))
		tmp = tmp->next;
	if (tmp && !ft_strcmp(tmp->var, name))
	{
		ft_free(1, &tmp->value);
		tmp->value = ft_strdup(value);
	}
	else
	{
		if ((new = malloc(sizeof(t_env))))
		{
			new->var = ft_strdup(name);
			new->value = ft_strdup(value);
			new->next = NULL;
		}
		if (!tmp)
			*env = new;
		else
			tmp->next = new;
	}
}

void	clear_env(t_env **env)
{
	t_env	*prev;
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		ft_free(3, &prev->var, &prev->value, &prev);
	}
	env = NULL;
}

char	**envlist_to_tab(t_env **env)
{
	t_env	*tmp;
	char	**envtab;
	int		i;

	tmp = *env;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	envtab = malloc(sizeof(char *) * (i + 1));
	tmp = *env;
	i = 0;
	while (tmp)
	{
		envtab[i] = join_char(tmp->var, tmp->value, '=');
		tmp = tmp->next;
		i++;
	}
	envtab[i] = NULL;
	return (envtab);
}

void	envtab_to_list(char **envtab, t_env **env)
{
	char	**tab;
	int		i;

	i = -1;
	while (envtab[++i])
	{
		tab = ft_strsplit(envtab[i], '=');
		add_env_elem(env, tab[0], tab[1]);
		ft_free_tab(tab);
	}
}
