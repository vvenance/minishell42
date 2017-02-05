# include "../inc/minishell.h"

int main(int ac, char **av, char **envp)
{
	t_env	*env;
	t_env	*tmpenv;
	char	*line;

	env = NULL;
	if (envp[0])
		envtab_to_list(envp, &env);
	else
		env = NULL;
	while (42)
	{
		ft_putstr("\\o/>");
		tmpenv = NULL;
		get_next_line(0, &line);
		line = clean_user_entry(line);
		builtin_or_exec(line, &env, &tmpenv);
		ft_free(1, &line);
	}
	return (0);
}