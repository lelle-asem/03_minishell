#include "ft_minishell.h"

//flag = 1 env
//flag = 2 export
//flag = 3 set
void	run_commands(char **commands, t_pipes *pipes) //t_env *env)
{
	t_env	*env;
	pid_t	pid;

	env = pipes->env;
	if (ft_strncmp(commands[0], "env", 4) == 0)
		g_exitcode = bldin_env(env);
	else if (ft_strncmp(commands[0], "unset", 6) == 0)
		g_exitcode = bldin_unset(&env, commands);
	else if (ft_strncmp(commands[0], "pwd", 4) == 0)
		g_exitcode = bldin_pwd();
	else if (ft_strncmp(commands[0], "export", 7) == 0 || \
		ft_strncmp(commands[0], "set_local", 10) == 0)
		g_exitcode = bldin_export(&env, commands);
	else if (ft_strncmp(commands[0], "echo", 5) == 0)
		g_exitcode = bldin_echo(commands);
	else if (ft_strncmp(commands[0], "cd", 3) == 0)
		g_exitcode = bldin_cd(env, commands);
	else if (ft_strncmp(commands[0], "exit", 5) == 0)
		bldin_exit(commands);
	else
	{
		if (pipes->fd_in == STD_IN && pipes->fd_out == STD_OUT)
		{
			pid = fork();
			if (!pid)
			{
				g_exitcode = other_cmd(env, commands);
				if (g_exitcode)
					exit(g_exitcode);
			}
			waitpid(pid, 0, 0);
		}
		else
			g_exitcode = other_cmd(env, commands);
	}
}
