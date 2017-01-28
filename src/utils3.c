# include "../inc/minishell.h"

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