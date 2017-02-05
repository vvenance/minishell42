/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:15:27 by vvenance          #+#    #+#             */
/*   Updated: 2017/02/05 15:15:29 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
