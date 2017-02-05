/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:15:58 by vvenance          #+#    #+#             */
/*   Updated: 2017/02/05 15:16:00 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_free(1, &tab[i]);
		i++;
	}
	ft_free(1, &tab);
	tab = NULL;
}

char	*join_char(char *str, char *str2, char c)
{
	int		i;
	int		j;
	char	*newstr;

	i = ft_strlen(str);
	i = i + ft_strlen(str2);
	newstr = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = c;
	j = -1;
	while (str2[++j])
	{
		i++;
		newstr[i] = str2[j];
	}
	newstr[i + 1] = '\0';
	return (newstr);
}

void	display_list(t_env **env)
{
	t_env *tmp;

	tmp = *env;
	while (tmp)
	{
		ft_putstr(tmp->var);
		ft_putchar('=');
		if (ft_strcmp(tmp->value, "(null)"))
			ft_putstr(tmp->value);
		ft_putendl("");
		tmp = tmp->next;
	}
}

void	display_tab(char **envtab)
{
	int i;

	i = -1;
	while (envtab[++i])
		ft_putendl(envtab[i]);
}

char	*clean_user_entry(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}
