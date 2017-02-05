/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:16:05 by vvenance          #+#    #+#             */
/*   Updated: 2017/02/05 15:16:06 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*realloc_str(char *str, char *newstr)
{
	if (str)
		ft_free(1, &str);
	str = ft_strdup(newstr);
	return (str);
}

void	str_swap(char **str, char **str2)
{
	char *str3;

	str3 = ft_strdup(*str);
	ft_free(1, &(*str));
	*str = ft_strdup(*str2);
	ft_free(1, &(*str2));
	*str2 = ft_strdup(str3);
	ft_free(1, &str3);
}

char	*str_join_char(char *str1, char *str2, char c)
{
	char tstr[2];

	tstr[0] = c;
	tstr[1] = '\0';
	str1 = ft_strjoin_free(str1, tstr);
	str1 = ft_strjoin_free(str1, str2);
	return (str1);
}

char	**get_proper_tab(char *line)
{
	char	**tab;

	tab = NULL;
	tab = ft_strsplit(line, ' ');
	if (ft_strlen(line) == 3)
	{
		ft_free(1, &tab[1]);
		tab[1] = NULL;
	}
	return (tab);
}
