/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:15:14 by nakhalil          #+#    #+#             */
/*   Updated: 2025/03/26 03:48:05 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b, char **args, int args_allocated)
{
	free_stack(a);
	free_stack(b);
	if (args_allocated)
		free_split(args);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
