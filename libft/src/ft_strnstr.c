/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:26:31 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:26:34 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	if (!ft_strlen(s2))
		return (((char *)s1));
	while (s1[i] != '\0')
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && s1[i + j] != '\0' && i + j < n)
			{
				j++;
				if (s2[j] == '\0')
					return (char *)(&s1[i]);
			}
		}
		i++;
	}
	return (NULL);
}
