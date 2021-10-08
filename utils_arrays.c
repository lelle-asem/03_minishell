#include "minishell.h"

int	len_arr(char **arr)
{
	int	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}

void	ft_free_2array(char **arr)
{
	int	i;

	i = -1;
	while (arr[i++] != NULL)
		free(arr[i]);
	free(arr);
}

char	**list_to_arr(t_env *env)
{
	char	**arr;
	int		len;
	int		i;

	i = -1;
	len = len_lst(env);
	arr = malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (0);
	while (i++ < len && env != NULL)
	{
		arr[i] = ft_strdup(env->key_val);
		if (arr[i] == NULL)
		{	
			while (i-- >= 0)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		env = env->next;
	}
	arr[i] = NULL;
	return (arr);
}
