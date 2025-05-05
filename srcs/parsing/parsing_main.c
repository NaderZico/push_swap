/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:13:59 by nakhalil          #+#    #+#             */
/*   Updated: 2025/04/02 15:23:48 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	allocate_stack(t_stack *stack, int size)
{
	stack->data = ft_calloc(size, sizeof(int));
	return (stack->data != NULL);
}

int	parse_input(char **args, t_stack *stack)
{
	int	size;

	if (!args)
		return (0);
	size = 0;
	while (args[size])
		size++;
	stack->size = size;
	if (!allocate_stack(stack, size) || !validate_arguments(args, stack)
		|| !normalize_main(stack))
		return (0);
	return (1);
}
