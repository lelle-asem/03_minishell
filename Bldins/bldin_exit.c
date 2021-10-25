/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bldin_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelle <lelle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:25:17 by lelle             #+#    #+#             */
/*   Updated: 2021/10/23 16:52:53 by gvolibea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

int	is_num(char *s)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (ft_isdigit(*s) == 1)
			s++;
		else
			return (0);
	}
	return (1);
}

int	bldin_exit(char **args)
{
	(void)args;
	if (is_num(args[1]) == 0)
	{
		printf("exit\nminishell: exit: %s: numeric argument required\n", args[1]);
		g_exitcode = 255;
	}
	else if (args[2] != NULL)
	{
		printf("exit\nminishell: exit: too many arguments\n");
		g_exitcode = 1;
		return (1);
	}
	else if (is_num(args[1]) == 1)
		g_exitcode = ft_atoi(args[1]);
	exit(g_exitcode);
}