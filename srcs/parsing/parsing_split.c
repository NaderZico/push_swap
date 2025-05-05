/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:06:23 by nakhalil          #+#    #+#             */
/*   Updated: 2025/03/28 01:03:37 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	add_split_to_args(char ***args, char **split, int *total)
{
	int		j;
	char	**new_args;

	j = 0;
	while (split[j])
	{
		new_args = ft_realloc(*args, sizeof(char *) * (*total), sizeof(char *)
				* (*total + 1));
		if (!new_args)
		{
			free_split(*args);
			return (0);
		}
		*args = new_args;
		(*args)[(*total)++] = ft_strdup(split[j]);
		j++;
	}
	return (1);
}

static int	build_args_array(char ***args, int argc, char **argv, int *total)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
		{
			free_split(split);
			free_split(*args);
			return (0);
		}
		if (!add_split_to_args(args, split, total))
		{
			free_split(split);
			free_split(*args);
			return (0);
		}
		free_split(split);
		i++;
	}
	return (1);
}

char	**split_args(int *argc, char **argv, int *allocated)
{
	char	**args;
	int		total;

	*allocated = 0;
	args = NULL;
	total = 0;
	if (!build_args_array(&args, *argc, argv, &total))
		return (NULL);
	args = ft_realloc(args, sizeof(char *) * total, sizeof(char *) * (total
				+ 1));
	if (!args)
		return (NULL);
	args[total] = NULL;
	*argc = total;
	*allocated = 1;
	return (args);
}
